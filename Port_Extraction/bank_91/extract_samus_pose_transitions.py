import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

class PoseEntry:
    def __init__(self, addr):
        self.new_input = rom.get_word(addr)
        self.cur_input = rom.get_word(addr+2)
        self.new_pose = rom.get_word(addr+4)

poses_text = open('poses.txt', 'r')
poses = []

transition_table_ptrs = []
transitions = [[]]
transition_ptrs_found = []

input_values = {
    1 << 4  : "kButton_R",
    1 << 5  : "kButton_L",
    1 << 6  : "kButton_X",
    1 << 7  : "kButton_A",
    1 << 8  : "kButton_Right",
    1 << 9  : "kButton_Left",
    1 << 10 : "kButton_Down",
    1 << 11 : "kButton_Up",
    1 << 12 : "kButton_Start",
    1 << 13 : "kButton_Select",
    1 << 14 : "kButton_Y",
    1 << 15 : "kButton_B",
}

def get_transition_table():
    rom.get_data(0x91, 0x9EE2, 0xA0DC, "uint16", transition_table_ptrs, "transition_table_ptr", True, True, -1, 1)
    return

def get_unique_transitions():
    for transition_ptr in transition_table_ptrs:
        if transition_ptr.word not in transition_ptrs_found:
            transition_ptrs_found.append(transition_ptr.word)
    return

def get_transitions_from_table_entries():
    index_into_transitions = 0
    data = 0
    for transition_ptr in transition_ptrs_found:

        while True:
            data = rom.get_word(0x91 << 16 | transition_ptr)
            if data == 0xFFFF:
                transitions[index_into_transitions].append(data)
                break

            new_transition = PoseEntry(0x91 << 16 | transition_ptr)
            transitions[index_into_transitions].append(new_transition)
            transition_ptr += 6

        transitions.append([])
        index_into_transitions += 1
    
    transitions.pop()
    return

def convert_data_into_inputs():
    index_into_transitions = 0
    index_into_inputs = 0
    for transition in transitions:
        for data in transition:
            if transitions[index_into_transitions][index_into_inputs] != 0xFFFF:
                value = 0x10
                new_input = data.new_input
                cur_input = data.cur_input
                transitions[index_into_transitions][index_into_inputs].new_input = ""
                transitions[index_into_transitions][index_into_inputs].cur_input = ""

                while value <= 0x8000:
                    if new_input & value != 0:
                        transitions[index_into_transitions][index_into_inputs].new_input += input_values.get(value) + "+"
                    if cur_input & value != 0:
                        transitions[index_into_transitions][index_into_inputs].cur_input += input_values.get(value) + "+"
                    value = value << 1

                if len(transitions[index_into_transitions][index_into_inputs].new_input) > 0:
                    transitions[index_into_transitions][index_into_inputs].new_input = transitions[index_into_transitions][index_into_inputs].new_input.rstrip(transitions[index_into_transitions][index_into_inputs].new_input[-1])
                else:
                    transitions[index_into_transitions][index_into_inputs].new_input = 0

                if len(transitions[index_into_transitions][index_into_inputs].cur_input) > 0:
                    transitions[index_into_transitions][index_into_inputs].cur_input = transitions[index_into_transitions][index_into_inputs].cur_input.rstrip(transitions[index_into_transitions][index_into_inputs].cur_input[-1])
                else:
                    transitions[index_into_transitions][index_into_inputs].cur_input = 0
                
                transitions[index_into_transitions][index_into_inputs].new_pose = poses[transitions[index_into_transitions][index_into_inputs].new_pose]

            index_into_inputs += 1
            if len(transitions[index_into_transitions]) < index_into_inputs + 1:
                index_into_transitions += 1
                index_into_inputs = 0

    return

def get_poses_from_text():
    for pose in poses_text:
        new_pose = pose.strip()
        poses.append(new_pose)
    return

def get_arrays():
    return

def get_switch_cases():
    case_transitions = "  switch (samus_pose) {\n"
    index_into_transitions = 0
    transition_found_flag = False
    for transition_ptr in transition_table_ptrs:        

        for i in range(index_into_transitions):
            if transition_ptr.word == transition_table_ptrs[i].word:
                transition_found_flag = True
                #length = len(("Trans_" + hex(i)[2:].zfill(2)))
                index = case_transitions.find("Trans_" + hex(i)[2:].zfill(2))
                #case_transitions = case_transitions[:index + length] + "_" + (hex(index_into_transitions)[2:].zfill(2)) + case_transitions[index + length:]
                case_transitions = case_transitions[:index - 8] + "\n    case " + poses[index_into_transitions] + ": " + case_transitions[index - 8:]
                break
        
        if transition_found_flag == True:
            transition_found_flag = False
            index_into_transitions += 1
            continue
        case_transitions += "    case " + poses[index_into_transitions] + ": "
        transition_number = hex(index_into_transitions)[2:].zfill(2)
        index_into_transitions += 1
        case_transitions += "return Trans_" + transition_number + ";\n"
    
    case_transitions += "  }"
    return case_transitions

def get_transition_arrays():
    case_transitions = get_switch_cases()
    transition_arrays = ""
    index_into_transitions = 0
    indices = [i for i in range(len(case_transitions)) if case_transitions.startswith(' Trans_', i)]
    for transition in transitions:
        transition_arrays += "  static uint16"
        transition_arrays += case_transitions[indices[index_into_transitions]:indices[index_into_transitions] + 9]
        transition_arrays += "[] = {  //  " + str(hex(0x91 << 16 | transition_ptrs_found[index_into_transitions])) + "\n"
        for data in transition:
            if data != 0xFFFF:
                transition_arrays += "    %-35s, " % str(data.new_input)
                transition_arrays += "%-35s, " % str(data.cur_input)
                transition_arrays += "%-35s, \n" % str(data.new_pose)
            else:
                transition_arrays += "    " + str(hex(data)) + "\n  };\n\n"
        index_into_transitions += 1
    return transition_arrays

def output_samus_pose_transition_table():
    cases = get_switch_cases()
    arrays = get_transition_arrays()
    output = "uint16* kPoseTransitionTable(void) {\n" + arrays + cases + "\n}"
    sys.stdout.write(output)
    return

get_transition_table()
get_unique_transitions()
get_transitions_from_table_entries()
get_poses_from_text()
convert_data_into_inputs()
#get_transition_arrays()
#get_switch_cases()
output_samus_pose_transition_table()
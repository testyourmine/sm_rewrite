import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kMotherBrain_FakeDeathExplosionsXYPositions = []
kMotherBrainTubesFallingFuncPtrs = []
kMotherBrain_ExplosionsXYOffsets = []
kMotherBrain_AttackInstrListPtrs = []
kMotherBrain_RainbowBeamPalettes = []
kMotherBrain_WalkForwardsFuncPtrs = []
kMotherBrain_WalkBackwardsFuncPtrs = []
kShitroid_FadingToBlack = []
kShitroid_DeathExplosionsXYOffsets = []
kShitroid_HealthBasedPalettes_Shell = []
kShitroid_HealthBasedPalettes_Innards = []
kMotherBrain_PaletteSetPtrs = []
kDeadTorizo_VramWriteTableIndices_1 = []
kDeadTorizo_VramWriteTableIndices_2 = []
kDeadTorizo_SandHeapDestinationOffsets = []
kDeadTorizo_SandHeapSourceOffsets = []
kDeadTorizo_TileData = []
kDeadZoomer_InstrListPtrs = []
kDeadZoomer_CorpseRottingDefinitionPtrs = []
kDeadRipper_InstrListPtrs = []
kDeadRipper_CorpseRottingDefinitionPtrs = []
kDeadSkree_InstrListPtrs = []
kDeadSkree_CorpseRottingDefinitionPtrs = []
kDeadMonsters_Tab0 = []
kDeadMonsters_Tab1 = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A9():
    rom.get_data(0xA9, 0x8929, 0x8949, "uint16", kMotherBrain_FakeDeathExplosionsXYPositions, "kMotherBrain_FakeDeathExplosionsXYPositions", False, True, 2, 1)
    rom.get_data(0xA9, 0x8B7B, 0x8B85, "uint16", kMotherBrainTubesFallingFuncPtrs, "kMotherBrainTubesFallingFuncPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xB099, 0xB109, "uint16", kMotherBrain_ExplosionsXYOffsets, "kMotherBrain_ExplosionsXYOffsets", True, True, 8, 2)
    rom.get_data(0xA9, 0xB6D4, 0xB6DC, "uint16", kMotherBrain_AttackInstrListPtrs, "kMotherBrain_AttackInstrListPtrs", True, True, -1, 1)
    rom.get_data(0xAD, 0xE434, 0xE44A, "uint16", kMotherBrain_RainbowBeamPalettes, "kMotherBrain_RainbowBeamPalettes", True, True, -1, 1)
    rom.get_data(0xA9, 0xC61E, 0xC62A, "uint16", kMotherBrain_WalkForwardsFuncPtrs, "kMotherBrain_WalkForwardsFuncPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xC664, 0xC670, "uint16", kMotherBrain_WalkBackwardsFuncPtrs, "kMotherBrain_WalkBackwardsFuncPtrs", True, True, -1, 1)
    rom.get_data(0xAD, 0xE8E2, 0xE8F0, "uint16", kShitroid_FadingToBlack, "kShitroid_FadingToBlack", True, True, -1, 1)
    rom.get_data(0xA9, 0xCDFC, 0xCE24, "uint16", kShitroid_DeathExplosionsXYOffsets, "kShitroid_DeathExplosionsXYOffsets", True, True, 2, 1)
    rom.get_data(0xAD, 0xE7E2, 0xE7F2, "uint16", kShitroid_HealthBasedPalettes_Shell, "kShitroid_HealthBasedPalettes_Shell", True, True, -1, 1)
    rom.get_data(0xAD, 0xE882, 0xE892, "uint16", kShitroid_HealthBasedPalettes_Innards, "kShitroid_HealthBasedPalettes_Innards", True, True, -1, 1)
    rom.get_data(0xA9, 0xD260, 0xD264, "uint16", kMotherBrain_PaletteSetPtrs, "kMotherBrain_PaletteSetPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD583, 0xD5BD, "uint16", kDeadTorizo_VramWriteTableIndices_1, "kDeadTorizo_VramWriteTableIndices_1", True, True, 4, 1)
    rom.get_data(0xA9, 0xD549, 0xD583, "uint16", kDeadTorizo_VramWriteTableIndices_2, "kDeadTorizo_VramWriteTableIndices_2", True, True, 4, 1)
    rom.get_data(0xA9, 0xD67C, 0xD69C, "uint16", kDeadTorizo_SandHeapDestinationOffsets, "kDeadTorizo_SandHeapDestinationOffsets", True, True, -1, 1)
    rom.get_data(0xA9, 0xD69C, 0xD6BC, "uint16", kDeadTorizo_SandHeapSourceOffsets, "kDeadTorizo_SandHeapSourceOffsets", True, True, -1, 1)
    #rom.get_data(0xB7, 0xA800, 0xA80F, "uint16", kDeadTorizo_TileData, "kDeadTorizo_TileData", True, True, -1, 1)
    rom.get_data(0xA9, 0xD86A, 0xD870, "uint16", kDeadZoomer_InstrListPtrs, "kDeadZoomer_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD870, 0xD876, "uint16", kDeadZoomer_CorpseRottingDefinitionPtrs, "kDeadZoomer_CorpseRottingDefinitionPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD897, 0xD89B, "uint16", kDeadRipper_InstrListPtrs, "kDeadRipper_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD89B, 0xD89F, "uint16", kDeadRipper_CorpseRottingDefinitionPtrs, "kDeadRipper_CorpseRottingDefinitionPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD8C0, 0xD8C6, "uint16", kDeadSkree_InstrListPtrs, "kDeadSkree_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD8C6, 0xD8CC, "uint16", kDeadSkree_CorpseRottingDefinitionPtrs, "kDeadSkree_CorpseRottingDefinitionPtrs", True, True, -1, 1)
    rom.get_data(0xA9, 0xD951, 0xD959, "uint16", kDeadMonsters_Tab0, "kDeadMonsters_Tab0", True, True, -1, 1)
    rom.get_data(0xA9, 0xD959, 0xD961, "uint16", kDeadMonsters_Tab1, "kDeadMonsters_Tab1", True, True, -1, 1)
    return

get_A9()
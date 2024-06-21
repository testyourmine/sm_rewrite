#pragma once

#include "ida_types.h"
#include "funcs.h"

extern RotationMatrix kCeresElevatorShaftMode7TransformationMatrix[69];

RoomDefHeader get_RoomDefHeader(uint16 room) {
  switch (room) {
    case 0x91f8: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 23, .y_coordinate_on_map =  0, .width =  9, .height =  5, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x927b, };
    case 0x92b3: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 18, .y_coordinate_on_map =  2, .width =  5, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x92f9, };
    case 0x92fd: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 18, .y_coordinate_on_map =  4, .width =  5, .height =  5, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9362, };
    case 0x93aa: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 32, .y_coordinate_on_map =  1, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x93d1, };
    case 0x93d5: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 18, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x93fc, };
    case 0x93fe: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 38, .y_coordinate_on_map =  0, .width =  8, .height =  6, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9425, };
    case 0x9461: return (RoomDefHeader){ .semiunique_room_number =  6, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 41, .y_coordinate_on_map =  2, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9488, };
    case 0x948c: return (RoomDefHeader){ .semiunique_room_number =  7, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 33, .y_coordinate_on_map =  4, .width =  3, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x94b3, };
    case 0x94cc: return (RoomDefHeader){ .semiunique_room_number =  8, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 52, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x94f3, };
    case 0x94fd: return (RoomDefHeader){ .semiunique_room_number =  9, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 49, .y_coordinate_on_map =  0, .width =  7, .height =  6, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9524, };
    case 0x9552: return (RoomDefHeader){ .semiunique_room_number = 10, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 56, .y_coordinate_on_map =  4, .width =  1, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9579, };
    case 0x957d: return (RoomDefHeader){ .semiunique_room_number = 11, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 53, .y_coordinate_on_map =  8, .width =  4, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x95a4, };
    case 0x95a8: return (RoomDefHeader){ .semiunique_room_number = 12, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 52, .y_coordinate_on_map =  9, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x95cf, };
    case 0x95d4: return (RoomDefHeader){ .semiunique_room_number = 13, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 32, .y_coordinate_on_map =  4, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x95fb, };
    case 0x95ff: return (RoomDefHeader){ .semiunique_room_number = 14, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 36, .y_coordinate_on_map =  4, .width =  2, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9626, };
    case 0x962a: return (RoomDefHeader){ .semiunique_room_number = 15, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 34, .y_coordinate_on_map =  7, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9651, };
    case 0x965b: return (RoomDefHeader){ .semiunique_room_number = 16, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 12, .y_coordinate_on_map =  2, .width =  6, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9682, };
    case 0x968f: return (RoomDefHeader){ .semiunique_room_number = 17, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 43, .y_coordinate_on_map =  2, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x96b6, };
    case 0x96ba: return (RoomDefHeader){ .semiunique_room_number = 18, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 18, .y_coordinate_on_map =  9, .width =  3, .height =  9, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x971f, };
    case 0x975c: return (RoomDefHeader){ .semiunique_room_number = 19, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 20, .y_coordinate_on_map = 17, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x97a1, };
    case 0x97b5: return (RoomDefHeader){ .semiunique_room_number = 20, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 23, .y_coordinate_on_map = 17, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x97fa, };
    case 0x9804: return (RoomDefHeader){ .semiunique_room_number = 21, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 25, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9869, };
    case 0x9879: return (RoomDefHeader){ .semiunique_room_number = 22, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 22, .y_coordinate_on_map =  6, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x98de, };
    case 0x98e2: return (RoomDefHeader){ .semiunique_room_number = 23, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 20, .y_coordinate_on_map =  7, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9909, };
    case 0x990d: return (RoomDefHeader){ .semiunique_room_number = 24, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 12, .y_coordinate_on_map =  4, .width =  6, .height =  3, .up_scroller_ = 160, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9934, };
    case 0x9938: return (RoomDefHeader){ .semiunique_room_number = 25, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map =  6, .y_coordinate_on_map =  8, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x995f, };
    case 0x9969: return (RoomDefHeader){ .semiunique_room_number = 26, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map =  7, .y_coordinate_on_map =  8, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9990, };
    case 0x9994: return (RoomDefHeader){ .semiunique_room_number = 27, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 23, .y_coordinate_on_map =  7, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x99bb, };
    case 0x99bd: return (RoomDefHeader){ .semiunique_room_number = 28, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 11, .y_coordinate_on_map =  2, .width =  1, .height =  7, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x99e4, };
    case 0x99f9: return (RoomDefHeader){ .semiunique_room_number = 29, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 21, .y_coordinate_on_map =  9, .width =  4, .height =  8, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9a20, };
    case 0x9a44: return (RoomDefHeader){ .semiunique_room_number = 30, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 17, .y_coordinate_on_map =  7, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9a8a, };
    case 0x9a90: return (RoomDefHeader){ .semiunique_room_number = 31, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 16, .y_coordinate_on_map =  7, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9ad6, };
    case 0x9ad9: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  9, .y_coordinate_on_map =  0, .width =  4, .height = 12, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9b00, };
    case 0x9b5b: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 23, .y_coordinate_on_map =  1, .width =  2, .height =  9, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9b82, };
    case 0x9b9d: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  6, .y_coordinate_on_map =  4, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9bc4, };
    case 0x9bc8: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 10, .y_coordinate_on_map =  3, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9bef, };
    case 0x9c07: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 13, .y_coordinate_on_map =  4, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9c2e, };
    case 0x9c35: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  5, .y_coordinate_on_map =  4, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9c5c, };
    case 0x9c5e: return (RoomDefHeader){ .semiunique_room_number =  6, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  6, .y_coordinate_on_map =  6, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9c85, };
    case 0x9c89: return (RoomDefHeader){ .semiunique_room_number =  7, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  5, .y_coordinate_on_map =  7, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9cb0, };
    case 0x9cb3: return (RoomDefHeader){ .semiunique_room_number =  8, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 10, .y_coordinate_on_map =  6, .width =  7, .height =  7, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9cda, };
    case 0x9d19: return (RoomDefHeader){ .semiunique_room_number =  9, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 15, .y_coordinate_on_map =  4, .width =  5, .height = 10, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9d40, };
    case 0x9d9c: return (RoomDefHeader){ .semiunique_room_number = 10, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 19, .y_coordinate_on_map =  4, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9dc3, };
    case 0x9dc7: return (RoomDefHeader){ .semiunique_room_number = 11, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 22, .y_coordinate_on_map =  1, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9e0d, };
    case 0x9e11: return (RoomDefHeader){ .semiunique_room_number = 12, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 15, .y_coordinate_on_map =  7, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9e38, };
    case 0x9e52: return (RoomDefHeader){ .semiunique_room_number = 13, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 19, .y_coordinate_on_map = 10, .width =  8, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9e79, };
    case 0x9e9f: return (RoomDefHeader){ .semiunique_room_number = 14, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 21, .y_coordinate_on_map =  8, .width =  8, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9ee5, };
    case 0x9f11: return (RoomDefHeader){ .semiunique_room_number = 15, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 29, .y_coordinate_on_map = 10, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9f57, };
    case 0x9f64: return (RoomDefHeader){ .semiunique_room_number = 16, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 30, .y_coordinate_on_map =  8, .width =  3, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9faa, };
    case 0x9fba: return (RoomDefHeader){ .semiunique_room_number = 17, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 27, .y_coordinate_on_map = 13, .width =  6, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0x9fe1, };
    case 0x9fe5: return (RoomDefHeader){ .semiunique_room_number = 18, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  8, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa00c, };
    case 0xa011: return (RoomDefHeader){ .semiunique_room_number = 19, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  6, .y_coordinate_on_map = 10, .width =  5, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa038, };
    case 0xa051: return (RoomDefHeader){ .semiunique_room_number = 20, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  5, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa078, };
    case 0xa07b: return (RoomDefHeader){ .semiunique_room_number = 21, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  9, .y_coordinate_on_map = 12, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa0a2, };
    case 0xa0a4: return (RoomDefHeader){ .semiunique_room_number = 22, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 20, .y_coordinate_on_map =  9, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa0cb, };
    case 0xa0d2: return (RoomDefHeader){ .semiunique_room_number = 23, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  8, .y_coordinate_on_map = 13, .width =  7, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa0f9, };
    case 0xa107: return (RoomDefHeader){ .semiunique_room_number = 24, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 28, .y_coordinate_on_map = 11, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa12e, };
    case 0xa130: return (RoomDefHeader){ .semiunique_room_number = 25, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 19, .y_coordinate_on_map =  7, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa157, };
    case 0xa15b: return (RoomDefHeader){ .semiunique_room_number = 26, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 21, .y_coordinate_on_map =  8, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa182, };
    case 0xa184: return (RoomDefHeader){ .semiunique_room_number = 27, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 15, .y_coordinate_on_map =  4, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa1ab, };
    case 0xa1ad: return (RoomDefHeader){ .semiunique_room_number = 28, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 30, .y_coordinate_on_map =  8, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa1d4, };
    case 0xa1d8: return (RoomDefHeader){ .semiunique_room_number = 29, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 29, .y_coordinate_on_map =  8, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa1ff, };
    case 0xa201: return (RoomDefHeader){ .semiunique_room_number = 30, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  8, .y_coordinate_on_map =  5, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa228, };
    case 0xa22a: return (RoomDefHeader){ .semiunique_room_number = 31, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map =  5, .y_coordinate_on_map = 11, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa251, };
    case 0xa253: return (RoomDefHeader){ .semiunique_room_number = 32, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 33, .y_coordinate_on_map =  9, .width =  1, .height = 10, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa27a, };
    case 0xa293: return (RoomDefHeader){ .semiunique_room_number = 33, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 25, .y_coordinate_on_map = 15, .width =  8, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa2ba, };
    case 0xa2ce: return (RoomDefHeader){ .semiunique_room_number = 34, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 23, .y_coordinate_on_map = 15, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa2f5, };
    case 0xa2f7: return (RoomDefHeader){ .semiunique_room_number = 35, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 34, .y_coordinate_on_map =  9, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa31e, };
    case 0xa322: return (RoomDefHeader){ .semiunique_room_number = 36, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 37, .y_coordinate_on_map =  4, .width =  3, .height =  8, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa349, };
    case 0xa37c: return (RoomDefHeader){ .semiunique_room_number = 37, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 35, .y_coordinate_on_map =  7, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa3a3, };
    case 0xa3ae: return (RoomDefHeader){ .semiunique_room_number = 38, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 34, .y_coordinate_on_map = 11, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa3d5, };
    case 0xa3dd: return (RoomDefHeader){ .semiunique_room_number = 39, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 34, .y_coordinate_on_map = 18, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa404, };
    case 0xa408: return (RoomDefHeader){ .semiunique_room_number = 40, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 36, .y_coordinate_on_map = 17, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa42f, };
    case 0xa447: return (RoomDefHeader){ .semiunique_room_number = 41, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 38, .y_coordinate_on_map = 17, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa46e, };
    case 0xa471: return (RoomDefHeader){ .semiunique_room_number = 42, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 44, .y_coordinate_on_map = 18, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa498, };
    case 0xa4b1: return (RoomDefHeader){ .semiunique_room_number = 43, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 43, .y_coordinate_on_map = 19, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa4d8, };
    case 0xa4da: return (RoomDefHeader){ .semiunique_room_number = 44, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 45, .y_coordinate_on_map = 18, .width =  4, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa501, };
    case 0xa521: return (RoomDefHeader){ .semiunique_room_number = 45, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 47, .y_coordinate_on_map = 19, .width =  6, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa567, };
    case 0xa56b: return (RoomDefHeader){ .semiunique_room_number = 46, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 53, .y_coordinate_on_map = 18, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_2_ReloadCre                              , .ptr_to_doorout = 0xa592, };
    case 0xa59f: return (RoomDefHeader){ .semiunique_room_number = 47, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 55, .y_coordinate_on_map = 18, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_1_DisableBg1 | kCreBitset_4_LargeTileset , .ptr_to_doorout = 0xa5e5, };
    case 0xa5ed: return (RoomDefHeader){ .semiunique_room_number = 48, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 12, .y_coordinate_on_map =  8, .width =  5, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa614, };
    case 0xa618: return (RoomDefHeader){ .semiunique_room_number = 49, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 32, .y_coordinate_on_map = 18, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa63f, };
    case 0xa641: return (RoomDefHeader){ .semiunique_room_number = 50, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 54, .y_coordinate_on_map = 18, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa668, };
    case 0xa66a: return (RoomDefHeader){ .semiunique_room_number = 51, .area_index_ = kArea_0_Crateria    , .x_coordinate_on_map = 17, .y_coordinate_on_map =  8, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa691, };
    case 0xa6a1: return (RoomDefHeader){ .semiunique_room_number = 52, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 41, .y_coordinate_on_map = 18, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa6c8, };
    case 0xa6e2: return (RoomDefHeader){ .semiunique_room_number = 53, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 57, .y_coordinate_on_map = 19, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_2_ReloadCre                              , .ptr_to_doorout = 0xa709, };
    case 0xa70b: return (RoomDefHeader){ .semiunique_room_number = 54, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 49, .y_coordinate_on_map = 18, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa732, };
    case 0xa734: return (RoomDefHeader){ .semiunique_room_number = 55, .area_index_ = kArea_1_Brinstar    , .x_coordinate_on_map = 38, .y_coordinate_on_map =  8, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa75b, };
    case 0xa75d: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  4, .y_coordinate_on_map =  3, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa784, };
    case 0xa788: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 14, .y_coordinate_on_map =  3, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa7af, };
    case 0xa7b3: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 11, .y_coordinate_on_map =  3, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa7da, };
    case 0xa7de: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 10, .y_coordinate_on_map =  0, .width =  1, .height =  7, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa805, };
    case 0xa815: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  3, .y_coordinate_on_map =  1, .width =  7, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa83c, };
    case 0xa865: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  4, .y_coordinate_on_map =  1, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa88c, };
    case 0xa890: return (RoomDefHeader){ .semiunique_room_number =  6, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  5, .y_coordinate_on_map =  2, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa8b7, };
    case 0xa8b9: return (RoomDefHeader){ .semiunique_room_number =  7, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  3, .y_coordinate_on_map =  1, .width =  2, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa8e0, };
    case 0xa8f8: return (RoomDefHeader){ .semiunique_room_number =  8, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  2, .y_coordinate_on_map =  4, .width =  1, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xa91f, };
    case 0xa923: return (RoomDefHeader){ .semiunique_room_number =  9, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  3, .y_coordinate_on_map =  7, .width = 13, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_2_ReloadCre                              , .ptr_to_doorout = 0xa94a, };
    case 0xa98d: return (RoomDefHeader){ .semiunique_room_number = 10, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 10, .width =  8, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_1_DisableBg1                             , .ptr_to_doorout = 0xa9d3, };
    case 0xa9e5: return (RoomDefHeader){ .semiunique_room_number = 11, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  7, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaa0c, };
    case 0xaa0e: return (RoomDefHeader){ .semiunique_room_number = 12, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 11, .y_coordinate_on_map =  6, .width =  4, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaa35, };
    case 0xaa41: return (RoomDefHeader){ .semiunique_room_number = 13, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  8, .y_coordinate_on_map =  5, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaa68, };
    case 0xaa82: return (RoomDefHeader){ .semiunique_room_number = 14, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 10, .y_coordinate_on_map = 10, .width =  2, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_2_ReloadCre                              , .ptr_to_doorout = 0xaaa9, };
    case 0xaab5: return (RoomDefHeader){ .semiunique_room_number = 15, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 11, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaadc, };
    case 0xaade: return (RoomDefHeader){ .semiunique_room_number = 16, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  9, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xab05, };
    case 0xab07: return (RoomDefHeader){ .semiunique_room_number = 17, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 10, .y_coordinate_on_map = 12, .width =  1, .height =  5, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xab2e, };
    case 0xab3b: return (RoomDefHeader){ .semiunique_room_number = 18, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 11, .y_coordinate_on_map = 15, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xab62, };
    case 0xab64: return (RoomDefHeader){ .semiunique_room_number = 19, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  7, .y_coordinate_on_map = 12, .width =  3, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xab8b, };
    case 0xab8f: return (RoomDefHeader){ .semiunique_room_number = 20, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  4, .y_coordinate_on_map = 15, .width =  8, .height =  3, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xabb6, };
    case 0xabd2: return (RoomDefHeader){ .semiunique_room_number = 21, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  6, .y_coordinate_on_map = 12, .width =  1, .height =  3, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xabf9, };
    case 0xac00: return (RoomDefHeader){ .semiunique_room_number = 22, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  4, .y_coordinate_on_map = 14, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xac27, };
    case 0xac2b: return (RoomDefHeader){ .semiunique_room_number = 23, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  3, .y_coordinate_on_map = 14, .width =  1, .height =  4, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xac52, };
    case 0xac5a: return (RoomDefHeader){ .semiunique_room_number = 24, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 18, .y_coordinate_on_map =  2, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xac81, };
    case 0xac83: return (RoomDefHeader){ .semiunique_room_number = 25, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 20, .y_coordinate_on_map =  2, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xacaa, };
    case 0xacb3: return (RoomDefHeader){ .semiunique_room_number = 26, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 22, .y_coordinate_on_map =  2, .width =  2, .height =  4, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xacda, };
    case 0xacf0: return (RoomDefHeader){ .semiunique_room_number = 27, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 25, .y_coordinate_on_map =  1, .width = 12, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xad17, };
    case 0xad1b: return (RoomDefHeader){ .semiunique_room_number = 28, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 37, .y_coordinate_on_map =  2, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xad5c, };
    case 0xad5e: return (RoomDefHeader){ .semiunique_room_number = 29, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 24, .y_coordinate_on_map =  3, .width =  6, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xad85, };
    case 0xadad: return (RoomDefHeader){ .semiunique_room_number = 30, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 25, .y_coordinate_on_map =  4, .width =  4, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xadd4, };
    case 0xadde: return (RoomDefHeader){ .semiunique_room_number = 31, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 29, .y_coordinate_on_map =  4, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xae05, };
    case 0xae07: return (RoomDefHeader){ .semiunique_room_number = 32, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 25, .y_coordinate_on_map =  6, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xae2e, };
    case 0xae32: return (RoomDefHeader){ .semiunique_room_number = 33, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 27, .y_coordinate_on_map =  6, .width =  3, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xae59, };
    case 0xae74: return (RoomDefHeader){ .semiunique_room_number = 34, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 25, .y_coordinate_on_map =  8, .width =  2, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xae9b, };
    case 0xaeb4: return (RoomDefHeader){ .semiunique_room_number = 35, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 23, .y_coordinate_on_map =  8, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaedb, };
    case 0xaedf: return (RoomDefHeader){ .semiunique_room_number = 36, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 22, .y_coordinate_on_map =  6, .width =  1, .height =  3, .up_scroller_ = 160, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaf06, };
    case 0xaf14: return (RoomDefHeader){ .semiunique_room_number = 37, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 22, .y_coordinate_on_map = 10, .width =  4, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaf3b, };
    case 0xaf3f: return (RoomDefHeader){ .semiunique_room_number = 38, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 21, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaf66, };
    case 0xaf72: return (RoomDefHeader){ .semiunique_room_number = 39, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 20, .y_coordinate_on_map =  5, .width =  2, .height =  2, .up_scroller_ = 160, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaf99, };
    case 0xafa3: return (RoomDefHeader){ .semiunique_room_number = 40, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 17, .y_coordinate_on_map =  4, .width =  5, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xafca, };
    case 0xafce: return (RoomDefHeader){ .semiunique_room_number = 41, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 16, .y_coordinate_on_map =  9, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xaff5, };
    case 0xaffb: return (RoomDefHeader){ .semiunique_room_number = 42, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 21, .y_coordinate_on_map =  9, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb022, };
    case 0xb026: return (RoomDefHeader){ .semiunique_room_number = 43, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 20, .y_coordinate_on_map =  9, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb04d, };
    case 0xb051: return (RoomDefHeader){ .semiunique_room_number = 44, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 23, .y_coordinate_on_map =  7, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb078, };
    case 0xb07a: return (RoomDefHeader){ .semiunique_room_number = 45, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 24, .y_coordinate_on_map =  1, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb0a1, };
    case 0xb0b4: return (RoomDefHeader){ .semiunique_room_number = 46, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map =  9, .y_coordinate_on_map =  4, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb0db, };
    case 0xb0dd: return (RoomDefHeader){ .semiunique_room_number = 47, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 21, .y_coordinate_on_map =  3, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb104, };
    case 0xb106: return (RoomDefHeader){ .semiunique_room_number = 48, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 12, .y_coordinate_on_map =  5, .width =  8, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb12d, };
    case 0xb139: return (RoomDefHeader){ .semiunique_room_number = 49, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 19, .y_coordinate_on_map =  6, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb160, };
    case 0xb167: return (RoomDefHeader){ .semiunique_room_number = 50, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 11, .y_coordinate_on_map =  5, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb18e, };
    case 0xb192: return (RoomDefHeader){ .semiunique_room_number = 51, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 16, .y_coordinate_on_map =  8, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb1b9, };
    case 0xb1bb: return (RoomDefHeader){ .semiunique_room_number = 52, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 20, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb1e2, };
    case 0xb1e5: return (RoomDefHeader){ .semiunique_room_number = 53, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 15, .y_coordinate_on_map = 13, .width =  3, .height =  3, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb20c, };
    case 0xb236: return (RoomDefHeader){ .semiunique_room_number = 54, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 17, .y_coordinate_on_map = 11, .width =  8, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb25d, };
    case 0xb283: return (RoomDefHeader){ .semiunique_room_number = 55, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 18, .y_coordinate_on_map = 15, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb2c9, };
    case 0xb2da: return (RoomDefHeader){ .semiunique_room_number = 56, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 21, .y_coordinate_on_map = 14, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb301, };
    case 0xb305: return (RoomDefHeader){ .semiunique_room_number = 57, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 21, .y_coordinate_on_map = 15, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb32c, };
    case 0xb32e: return (RoomDefHeader){ .semiunique_room_number = 58, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 23, .y_coordinate_on_map = 16, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb374, };
    case 0xb37a: return (RoomDefHeader){ .semiunique_room_number = 59, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 24, .y_coordinate_on_map = 16, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb3a1, };
    case 0xb3a5: return (RoomDefHeader){ .semiunique_room_number = 60, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 25, .y_coordinate_on_map = 12, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb3cc, };
    case 0xb40a: return (RoomDefHeader){ .semiunique_room_number = 62, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 26, .y_coordinate_on_map =  9, .width =  4, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb431, };
    case 0xb457: return (RoomDefHeader){ .semiunique_room_number = 63, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 26, .y_coordinate_on_map = 14, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb47e, };
    case 0xb482: return (RoomDefHeader){ .semiunique_room_number = 64, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 27, .y_coordinate_on_map = 16, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb4a9, };
    case 0xb4ad: return (RoomDefHeader){ .semiunique_room_number = 65, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 30, .y_coordinate_on_map =  9, .width =  1, .height =  6, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb4d4, };
    case 0xb4e5: return (RoomDefHeader){ .semiunique_room_number = 66, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 31, .y_coordinate_on_map =  9, .width =  4, .height =  5, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb50c, };
    case 0xb510: return (RoomDefHeader){ .semiunique_room_number = 67, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 33, .y_coordinate_on_map =  5, .width =  5, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb537, };
    case 0xb55a: return (RoomDefHeader){ .semiunique_room_number = 68, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 37, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb581, };
    case 0xb585: return (RoomDefHeader){ .semiunique_room_number = 69, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 35, .y_coordinate_on_map =  9, .width =  3, .height =  5, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb5ac, };
    case 0xb5d5: return (RoomDefHeader){ .semiunique_room_number = 70, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 32, .y_coordinate_on_map = 14, .width =  6, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb5fc, };
    case 0xb62b: return (RoomDefHeader){ .semiunique_room_number = 71, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 30, .y_coordinate_on_map = 16, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb652, };
    case 0xb656: return (RoomDefHeader){ .semiunique_room_number = 72, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 29, .y_coordinate_on_map =  3, .width =  4, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb67d, };
    case 0xb698: return (RoomDefHeader){ .semiunique_room_number = 73, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 22, .y_coordinate_on_map = 17, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb6bf, };
    case 0xb6c1: return (RoomDefHeader){ .semiunique_room_number = 74, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 20, .y_coordinate_on_map = 14, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb6e8, };
    case 0xb6ee: return (RoomDefHeader){ .semiunique_room_number = 75, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 35, .y_coordinate_on_map =  6, .width =  3, .height =  6, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb715, };
    case 0xb741: return (RoomDefHeader){ .semiunique_room_number = 76, .area_index_ = kArea_2_Norfair     , .x_coordinate_on_map = 36, .y_coordinate_on_map = 12, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xb768, };
    case 0xc98e: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 10, .y_coordinate_on_map = 11, .width =  6, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xc9d4, };
    case 0xca08: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 12, .y_coordinate_on_map = 14, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xca4e, };
    case 0xca52: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 12, .y_coordinate_on_map = 10, .width =  7, .height =  1, .up_scroller_ =   0, .down_scroller_ =   0, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xca98, };
    case 0xcaae: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 19, .y_coordinate_on_map = 10, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcaf4, };
    case 0xcaf6: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 12, .y_coordinate_on_map = 11, .width =  6, .height =  8, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcb3c, };
    case 0xcb8b: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 19, .y_coordinate_on_map = 15, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcbd1, };
    case 0xcbd5: return (RoomDefHeader){ .semiunique_room_number =  6, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 21, .y_coordinate_on_map = 13, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcc1b, };
    case 0xcc27: return (RoomDefHeader){ .semiunique_room_number =  7, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 18, .y_coordinate_on_map = 13, .width =  3, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcc6d, };
    case 0xcc6f: return (RoomDefHeader){ .semiunique_room_number =  8, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 14, .y_coordinate_on_map = 19, .width =  5, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xccb5, };
    case 0xcccb: return (RoomDefHeader){ .semiunique_room_number =  9, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 13, .y_coordinate_on_map = 19, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcd11, };
    case 0xcd13: return (RoomDefHeader){ .semiunique_room_number = 10, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 19, .y_coordinate_on_map = 19, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcd59, };
    case 0xcd5c: return (RoomDefHeader){ .semiunique_room_number = 11, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 17, .y_coordinate_on_map = 15, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcda2, };
    case 0xcda8: return (RoomDefHeader){ .semiunique_room_number = 12, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 15, .y_coordinate_on_map = 17, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcdee, };
    case 0xcdf1: return (RoomDefHeader){ .semiunique_room_number = 13, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 18, .y_coordinate_on_map = 17, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xce37, };
    case 0xce40: return (RoomDefHeader){ .semiunique_room_number = 14, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 10, .y_coordinate_on_map = 13, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xce86, };
    case 0xce8a: return (RoomDefHeader){ .semiunique_room_number = 15, .area_index_ = kArea_3_WreckedShip , .x_coordinate_on_map = 17, .y_coordinate_on_map = 14, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xced0, };
    case 0xced2: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 19, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcef9, };
    case 0xcefb: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 11, .y_coordinate_on_map = 17, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcf41, };
    case 0xcf54: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 10, .y_coordinate_on_map = 18, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcf7b, };
    case 0xcf80: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 17, .width =  4, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcfa7, };
    case 0xcfc9: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 10, .y_coordinate_on_map =  9, .width =  3, .height =  8, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xcff0, };
    case 0xd017: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 13, .y_coordinate_on_map = 13, .width =  4, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd03e, };
    case 0xd055: return (RoomDefHeader){ .semiunique_room_number =  6, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 17, .y_coordinate_on_map = 12, .width =  3, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd07c, };
    case 0xd08a: return (RoomDefHeader){ .semiunique_room_number =  7, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 16, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd0b1, };
    case 0xd0b9: return (RoomDefHeader){ .semiunique_room_number =  8, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 12, .y_coordinate_on_map =  9, .width =  6, .height =  4, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd0e0, };
    case 0xd104: return (RoomDefHeader){ .semiunique_room_number =  9, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 12, .y_coordinate_on_map =  7, .width =  3, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd12b, };
    case 0xd13b: return (RoomDefHeader){ .semiunique_room_number = 10, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 12, .y_coordinate_on_map =  4, .width =  2, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd162, };
    case 0xd16d: return (RoomDefHeader){ .semiunique_room_number = 11, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 14, .y_coordinate_on_map =  4, .width =  4, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd194, };
    case 0xd1a3: return (RoomDefHeader){ .semiunique_room_number = 12, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 18, .y_coordinate_on_map =  7, .width =  2, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd1ca, };
    case 0xd1dd: return (RoomDefHeader){ .semiunique_room_number = 13, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 18, .y_coordinate_on_map =  4, .width =  4, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd204, };
    case 0xd21c: return (RoomDefHeader){ .semiunique_room_number = 14, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 16, .y_coordinate_on_map = 16, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd243, };
    case 0xd252: return (RoomDefHeader){ .semiunique_room_number = 15, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 17, .y_coordinate_on_map = 16, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd279, };
    case 0xd27e: return (RoomDefHeader){ .semiunique_room_number = 16, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map =  0, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd2a5, };
    case 0xd2aa: return (RoomDefHeader){ .semiunique_room_number = 17, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 27, .y_coordinate_on_map =  0, .width =  2, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd2d1, };
    case 0xd2d9: return (RoomDefHeader){ .semiunique_room_number = 18, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 27, .y_coordinate_on_map =  5, .width =  7, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd300, };
    case 0xd30b: return (RoomDefHeader){ .semiunique_room_number = 19, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 34, .y_coordinate_on_map =  0, .width =  1, .height =  6, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd332, };
    case 0xd340: return (RoomDefHeader){ .semiunique_room_number = 20, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 22, .y_coordinate_on_map =  2, .width =  4, .height =  6, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd367, };
    case 0xd387: return (RoomDefHeader){ .semiunique_room_number = 21, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 25, .y_coordinate_on_map =  0, .width =  1, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd3ae, };
    case 0xd3b6: return (RoomDefHeader){ .semiunique_room_number = 22, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 17, .y_coordinate_on_map = 17, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd3dd, };
    case 0xd3df: return (RoomDefHeader){ .semiunique_room_number = 23, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 35, .y_coordinate_on_map =  4, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd406, };
    case 0xd408: return (RoomDefHeader){ .semiunique_room_number = 24, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 22, .y_coordinate_on_map =  5, .width =  1, .height = 10, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd42f, };
    case 0xd433: return (RoomDefHeader){ .semiunique_room_number = 25, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map =  5, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd45a, };
    case 0xd461: return (RoomDefHeader){ .semiunique_room_number = 26, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 18, .y_coordinate_on_map = 16, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd488, };
    case 0xd48e: return (RoomDefHeader){ .semiunique_room_number = 27, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 22, .y_coordinate_on_map = 15, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd4b5, };
    case 0xd4c2: return (RoomDefHeader){ .semiunique_room_number = 28, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 23, .y_coordinate_on_map = 16, .width =  3, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd4e9, };
    case 0xd4ef: return (RoomDefHeader){ .semiunique_room_number = 29, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 20, .y_coordinate_on_map = 14, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd516, };
    case 0xd51e: return (RoomDefHeader){ .semiunique_room_number = 30, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 23, .y_coordinate_on_map = 14, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd545, };
    case 0xd54d: return (RoomDefHeader){ .semiunique_room_number = 31, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 21, .y_coordinate_on_map = 12, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd574, };
    case 0xd57a: return (RoomDefHeader){ .semiunique_room_number = 32, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 23, .y_coordinate_on_map = 12, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd5a1, };
    case 0xd5a7: return (RoomDefHeader){ .semiunique_room_number = 33, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 20, .y_coordinate_on_map =  9, .width =  6, .height =  3, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd5ce, };
    case 0xd5ec: return (RoomDefHeader){ .semiunique_room_number = 34, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map =  7, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd613, };
    case 0xd617: return (RoomDefHeader){ .semiunique_room_number = 35, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 20, .y_coordinate_on_map =  8, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd63e, };
    case 0xd646: return (RoomDefHeader){ .semiunique_room_number = 36, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map = 13, .width =  2, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd66d, };
    case 0xd69a: return (RoomDefHeader){ .semiunique_room_number = 37, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 27, .y_coordinate_on_map = 14, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd6c1, };
    case 0xd6d0: return (RoomDefHeader){ .semiunique_room_number = 38, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 32, .y_coordinate_on_map = 15, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd6f7, };
    case 0xd6fd: return (RoomDefHeader){ .semiunique_room_number = 39, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map = 10, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd724, };
    case 0xd72a: return (RoomDefHeader){ .semiunique_room_number = 40, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 34, .y_coordinate_on_map =  6, .width =  7, .height =  2, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd751, };
    case 0xd765: return (RoomDefHeader){ .semiunique_room_number = 41, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 19, .y_coordinate_on_map = 11, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd78c, };
    case 0xd78f: return (RoomDefHeader){ .semiunique_room_number = 42, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 41, .y_coordinate_on_map =  7, .width =  2, .height =  3, .up_scroller_ = 144, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd7d5, };
    case 0xd7e4: return (RoomDefHeader){ .semiunique_room_number = 43, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map =  8, .width =  7, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd80b, };
    case 0xd81a: return (RoomDefHeader){ .semiunique_room_number = 44, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 41, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd841, };
    case 0xd845: return (RoomDefHeader){ .semiunique_room_number = 45, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 38, .y_coordinate_on_map =  8, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd86c, };
    case 0xd86e: return (RoomDefHeader){ .semiunique_room_number = 46, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 26, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd895, };
    case 0xd898: return (RoomDefHeader){ .semiunique_room_number = 47, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 28, .y_coordinate_on_map =  9, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd8bf, };
    case 0xd8c5: return (RoomDefHeader){ .semiunique_room_number = 48, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 28, .y_coordinate_on_map = 15, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd90b, };
    case 0xd913: return (RoomDefHeader){ .semiunique_room_number = 49, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 33, .y_coordinate_on_map =  6, .width =  5, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd93a, };
    case 0xd95e: return (RoomDefHeader){ .semiunique_room_number = 50, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 24, .y_coordinate_on_map =  8, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd9a4, };
    case 0xd9aa: return (RoomDefHeader){ .semiunique_room_number = 51, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 38, .y_coordinate_on_map = 10, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd9d1, };
    case 0xd9d4: return (RoomDefHeader){ .semiunique_room_number = 52, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 42, .y_coordinate_on_map =  6, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xd9fb, };
    case 0xd9fe: return (RoomDefHeader){ .semiunique_room_number = 53, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 27, .y_coordinate_on_map =  6, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xda25, };
    case 0xda2b: return (RoomDefHeader){ .semiunique_room_number = 54, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 28, .y_coordinate_on_map =  6, .width =  5, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xda52, };
    case 0xda60: return (RoomDefHeader){ .semiunique_room_number = 55, .area_index_ = kArea_4_Maridia     , .x_coordinate_on_map = 39, .y_coordinate_on_map =  9, .width =  2, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_1_DisableBg1                             , .ptr_to_doorout = 0xdaa6, };
    case 0xdaae: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 20, .y_coordinate_on_map =  9, .width =  1, .height =  4, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdad5, };
    case 0xdae1: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 14, .y_coordinate_on_map = 12, .width =  6, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdb27, };
    case 0xdb31: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 13, .y_coordinate_on_map = 12, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdb77, };
    case 0xdb7d: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 14, .y_coordinate_on_map = 13, .width =  6, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdbc3, };
    case 0xdbcd: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 20, .y_coordinate_on_map = 13, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdc13, };
    case 0xdc19: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 19, .y_coordinate_on_map = 15, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdc5f, };
    case 0xdc65: return (RoomDefHeader){ .semiunique_room_number =  6, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 17, .y_coordinate_on_map = 15, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdcab, };
    case 0xdcb1: return (RoomDefHeader){ .semiunique_room_number =  7, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 13, .y_coordinate_on_map = 15, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdcf7, };
    case 0xdcff: return (RoomDefHeader){ .semiunique_room_number =  8, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 15, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdd26, };
    case 0xdd2e: return (RoomDefHeader){ .semiunique_room_number =  9, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 11, .y_coordinate_on_map = 16, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdd55, };
    case 0xdd58: return (RoomDefHeader){ .semiunique_room_number = 10, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 13, .y_coordinate_on_map = 18, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xddbc, };
    case 0xddc4: return (RoomDefHeader){ .semiunique_room_number = 11, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 13, .y_coordinate_on_map = 16, .width =  4, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xddeb, };
    case 0xddf3: return (RoomDefHeader){ .semiunique_room_number = 12, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 17, .y_coordinate_on_map = 16, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xde1a, };
    case 0xde23: return (RoomDefHeader){ .semiunique_room_number = 13, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 16, .y_coordinate_on_map = 17, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xde4a, };
    case 0xde4d: return (RoomDefHeader){ .semiunique_room_number = 14, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 11, .y_coordinate_on_map = 18, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xde74, };
    case 0xde7a: return (RoomDefHeader){ .semiunique_room_number = 15, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 11, .y_coordinate_on_map = 19, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdea1, };
    case 0xdea7: return (RoomDefHeader){ .semiunique_room_number = 16, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 12, .y_coordinate_on_map = 19, .width =  6, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdece, };
    case 0xdede: return (RoomDefHeader){ .semiunique_room_number = 17, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 18, .y_coordinate_on_map = 16, .width =  3, .height =  6, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdf05, };
    case 0xdf1b: return (RoomDefHeader){ .semiunique_room_number = 18, .area_index_ = kArea_5_Tourian     , .x_coordinate_on_map = 21, .y_coordinate_on_map = 12, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdf42, };
    case 0xdf45: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_6_Ceres       , .x_coordinate_on_map = 12, .y_coordinate_on_map = 13, .width =  1, .height =  3, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_1_DisableBg1 | kCreBitset_4_LargeTileset , .ptr_to_doorout = 0xdf8b, };
    case 0xdf8d: return (RoomDefHeader){ .semiunique_room_number =  1, .area_index_ = kArea_6_Ceres       , .x_coordinate_on_map = 13, .y_coordinate_on_map = 15, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xdfd3, };
    case 0xdfd7: return (RoomDefHeader){ .semiunique_room_number =  2, .area_index_ = kArea_6_Ceres       , .x_coordinate_on_map = 15, .y_coordinate_on_map = 15, .width =  1, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xe01d, };
    case 0xe021: return (RoomDefHeader){ .semiunique_room_number =  3, .area_index_ = kArea_6_Ceres       , .x_coordinate_on_map = 16, .y_coordinate_on_map = 16, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xe067, };
    case 0xe06b: return (RoomDefHeader){ .semiunique_room_number =  4, .area_index_ = kArea_6_Ceres       , .x_coordinate_on_map = 18, .y_coordinate_on_map = 16, .width =  2, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xe0b1, };
    case 0xe0b5: return (RoomDefHeader){ .semiunique_room_number =  5, .area_index_ = kArea_6_Ceres       , .x_coordinate_on_map = 20, .y_coordinate_on_map = 16, .width =  1, .height =  1, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = kCreBitset_1_DisableBg1 | kCreBitset_4_LargeTileset , .ptr_to_doorout = 0xe0fb, };
    case 0xe82c: return (RoomDefHeader){ .semiunique_room_number =  0, .area_index_ = kArea_7_Debug       , .x_coordinate_on_map =  0, .y_coordinate_on_map =  0, .width =  6, .height =  2, .up_scroller_ = 112, .down_scroller_ = 160, .cre_bitset_ = 0                                                   , .ptr_to_doorout = 0xe853, };
    default: Unreachable(); return (RoomDefHeader){ 0 };
  }
}

RoomDefStateSelect get_RoomDefStateSelect(uint16 state) {
  switch (state) {
    case 0x9203: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_14_ZebesTimebombSet, .state_ptr = 0x9261,  };
    case 0x9208: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_CollectedPowerBombs), .state_ptr = 0x9247,  };
    case 0x920c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x922d,  };
    case 0x9211: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x92be: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x92df,  };
    case 0x92c3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9308: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_14_ZebesTimebombSet, .state_ptr = 0x9348,  };
    case 0x930d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x932e,  };
    case 0x9312: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x93b5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x93e0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9409: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x946c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9497: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x94d7: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9508: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x955d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9588: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x95b3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x95df: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x960a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9635: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9666: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x969a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x96c5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_14_ZebesTimebombSet, .state_ptr = 0x9705,  };
    case 0x96ca: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x96eb,  };
    case 0x96cf: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9767: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_CollectedMorphBallAndMissiles), .state_ptr = 0x9787,  };
    case 0x976b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x97c0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_CollectedMorphBallAndMissiles), .state_ptr = 0x97e0,  };
    case 0x97c4: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x980f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_14_ZebesTimebombSet, .state_ptr = 0x984f,  };
    case 0x9814: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaTorizo, .state_ptr = 0x9835,  };
    case 0x9819: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9884: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_14_ZebesTimebombSet, .state_ptr = 0x98c4,  };
    case 0x9889: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaTorizo, .state_ptr = 0x98aa,  };
    case 0x988e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x98ed: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9918: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9943: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9974: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x999f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x99c8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9a04: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9a4f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x9a70,  };
    case 0x9a54: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9a9b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x9abc,  };
    case 0x9aa0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9ae4: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9b66: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9ba8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9bd3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9c12: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9c40: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9c69: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9c94: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9cbe: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9d24: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9da7: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9dd2: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaMiniBoss, .state_ptr = 0x9df3,  };
    case 0x9dd7: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9e1c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9e5d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9eaa: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x9ecb,  };
    case 0x9eaf: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9f1c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x9f3d,  };
    case 0x9f21: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9f6f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_0_ZebesAwake, .state_ptr = 0x9f90,  };
    case 0x9f74: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9fc5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0x9ff0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa01c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa05c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa086: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa0af: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa0dd: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa112: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa13b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa166: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa18f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa1b8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa1e3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa20c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa235: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa25e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa29e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa2d9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa302: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa32d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa387: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa3b9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa3e8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa413: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa452: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa47c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa4bc: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa4e5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa52c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xa54d,  };
    case 0xa531: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa576: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa5aa: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xa5cb,  };
    case 0xa5af: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa5f8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa623: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa64c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa675: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa6ac: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa6ed: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa716: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa73f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa768: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa793: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa7be: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa7e9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa820: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa870: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa89b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa8c4: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa903: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa92e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa998: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaMiniBoss, .state_ptr = 0xa9b9,  };
    case 0xa99d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xa9f0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaa19: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaa4c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaa8d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaac0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaae9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xab12: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xab46: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xab6f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xab9a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xabdd: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xac0b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xac36: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xac65: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xac8e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xacbe: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xacfb: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xad26: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xad69: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xadb8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xade9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xae12: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xae3d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xae7f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaebf: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaeea: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaf1f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaf4a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xaf7d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xafae: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xafd9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb006: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb031: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb05c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb085: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb0bf: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb0e8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb111: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb144: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb172: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb19d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb1c6: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb1f0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb241: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb28e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaTorizo, .state_ptr = 0xb2af,  };
    case 0xb293: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb2e5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb310: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb339: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xb35a,  };
    case 0xb33e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb385: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb3b0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb415: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb462: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb48d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb4b8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb4f0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb51b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb565: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb590: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb5e0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb636: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb661: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb6a3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb6cc: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb6f9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xb74c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xc999: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xc9ba,  };
    case 0xc99e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xca13: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xca34,  };
    case 0xca18: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xca5d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xca7e,  };
    case 0xca62: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcab9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcada,  };
    case 0xcabe: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcb01: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcb22,  };
    case 0xcb06: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcb96: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcbb7,  };
    case 0xcb9b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcbe0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcc01,  };
    case 0xcbe5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcc32: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcc53,  };
    case 0xcc37: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcc7a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcc9b,  };
    case 0xcc7f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xccd6: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xccf7,  };
    case 0xccdb: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcd1e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcd3f,  };
    case 0xcd23: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcd67: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcd88,  };
    case 0xcd6c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcdb3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xcdd4,  };
    case 0xcdb8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcdfc: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xce1d,  };
    case 0xce01: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xce4b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xce6c,  };
    case 0xce50: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xce95: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xceb6,  };
    case 0xce9a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcedd: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcf06: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_11_MaridiaNoobtubeBroken, .state_ptr = 0xcf27,  };
    case 0xcf0b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcf5f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcf8b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xcfd4: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd022: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd060: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd095: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd0c4: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd10f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd146: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd178: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd1ae: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd1e8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd227: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd25d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd289: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd2b5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd2e4: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd316: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd34b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd392: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd3c1: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd3ea: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd413: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd43e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd46c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd499: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd4cd: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd4fa: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd529: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd558: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd585: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd5b2: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd5f7: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd622: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd651: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd6a5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd6db: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd708: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd735: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd770: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd79a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xd7bb,  };
    case 0xd79f: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd7ef: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd825: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd850: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd879: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd8a3: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd8d0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_13_ShaktoolPathCleared, .state_ptr = 0xd8f1,  };
    case 0xd8d5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd91e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd969: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaMiniBoss, .state_ptr = 0xd98a,  };
    case 0xd96e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd9b5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xd9df: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xda09: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xda36: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xda6b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xda8c,  };
    case 0xda70: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdab9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdaec: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_16_1stMetroidHallCleared, .state_ptr = 0xdb0d,  };
    case 0xdaf1: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdb3c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_17_1stMetroidShaftCleared, .state_ptr = 0xdb5d,  };
    case 0xdb41: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdb88: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_18_2ndMetroidHallCleared, .state_ptr = 0xdba9,  };
    case 0xdb8d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdbd8: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_19_2ndMetroidShaftCleared, .state_ptr = 0xdbf9,  };
    case 0xdbdd: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdc24: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_20_Empty14h_Unused, .state_ptr = 0xdc45,  };
    case 0xdc29: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdc70: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_20_Empty14h_Unused, .state_ptr = 0xdc91,  };
    case 0xdc75: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdcbc: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_20_Empty14h_Unused, .state_ptr = 0xdcdd,  };
    case 0xdcc1: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdd0a: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdd39: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdd63: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_MainAreaBossDead), .state_ptr = 0xdda2,  };
    case 0xdd67: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsEventSet), .event_ = kEvent_2_MotherBrainGlassBroken, .state_ptr = 0xdd88,  };
    case 0xdd6c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xddcf: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xddfe: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xde2e: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xde58: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xde85: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdeb2: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdee9: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdf26: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdf50: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xdf71,  };
    case 0xdf55: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdf98: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xdfb9,  };
    case 0xdf9d: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xdfe2: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xe003,  };
    case 0xdfe7: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xe02c: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xe04d,  };
    case 0xe031: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xe076: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xe097,  };
    case 0xe07b: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xe0c0: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_IsBossDead), .area_boss = kBossBit_AreaBoss, .state_ptr = 0xe0e1,  };
    case 0xe0c5: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    case 0xe837: return (RoomDefStateSelect){ .func_ptr = FUNC16(RoomDefStateSelect_Finish), };
    default: Unreachable(); return (RoomDefStateSelect){ 0 };
  }
}

RoomDefRoomstate get_RoomDefRoomstate(uint16 room_state) {
  switch (room_state) {
    case 0x9261: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2c2bb), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8000, .enemy_population_ptr_ = 0x8c0d, .enemy_tilesets_ptr = 0x8283, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0x9283, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyLand_Shakes)        , .room_plm_header_ptr = 0x8026, .bg_data_ptr = 0xb76a, .room_setup_code = FUNC16(RoomSetup_ShakeDuringEscape)              , };
    case 0x9247: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2c2bb), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_UpperCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x80d0, .enemy_population_ptr_ = 0x883d, .enemy_tilesets_ptr = 0x8193, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0x9283, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyLand_)              , .room_plm_header_ptr = 0x8000, .bg_data_ptr = 0xb76a, .room_setup_code = FUNC16(RoomSetup_ScrollingSkyLand)               , };
    case 0x922d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2c2bb), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_EmptyCrateria , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x80c0, .enemy_population_ptr_ = 0x883d, .enemy_tilesets_ptr = 0x8193, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0x9283, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyLand_)              , .room_plm_header_ptr = 0x8000, .bg_data_ptr = 0xb76a, .room_setup_code = FUNC16(RoomSetup_ScrollingSkyLand)               , };
    case 0x9213: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2c2bb), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_EmptyCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x80c0, .enemy_population_ptr_ = 0x883d, .enemy_tilesets_ptr = 0x8193, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0x9283, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyLand_)              , .room_plm_header_ptr = 0x8000, .bg_data_ptr = 0xb76a, .room_setup_code = FUNC16(RoomSetup_ScrollingSkyLand)               , };
    case 0x92df: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2d6e8), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x80e0, .enemy_population_ptr_ = 0x847a, .enemy_tilesets_ptr = 0x80a1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8058, .bg_data_ptr = 0xb899, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x92c5: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2d6e8), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x80e0, .enemy_population_ptr_ = 0x847a, .enemy_tilesets_ptr = 0x80a1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8058, .bg_data_ptr = 0xb899, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x9348: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2dbc4), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8010, .enemy_population_ptr_ = 0x8da0, .enemy_tilesets_ptr = 0x8295, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9370, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ExplodeShakes)                  , .room_plm_header_ptr = 0x8104, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(RoomSetup_AfterSavingAnimals)             , };
    case 0x932e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2dbc4), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8050, .enemy_population_ptr_ = 0x8261, .enemy_tilesets_ptr = 0x8067, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9370, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x805a, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x9314: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2dbc4), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x80f0, .enemy_population_ptr_ = 0x86fa, .enemy_tilesets_ptr = 0x8185, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9370, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x805a, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x93b7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2e977), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8100, .enemy_population_ptr_ = 0x80d5, .enemy_tilesets_ptr = 0x801f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x93d3, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyLand_)              , .room_plm_header_ptr = 0x81cc, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x93e2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8110, .enemy_population_ptr_ = 0x85d8, .enemy_tilesets_ptr = 0x8129, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x81d4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x940b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc2eb45), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_UpperCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8112, .enemy_population_ptr_ = 0x8684, .enemy_tilesets_ptr = 0x8161, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0x9431, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyOcean_)             , .room_plm_header_ptr = 0x81dc, .bg_data_ptr = 0xb7ae, .room_setup_code = FUNC16(RoomSetup_ScrollingSkyOcean)              , };
    case 0x946e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc38e1f), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8122, .enemy_population_ptr_ = 0x897c, .enemy_tilesets_ptr = 0x81e1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x81fc, .bg_data_ptr = 0xb899, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x9499: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc38ffe), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8132, .enemy_population_ptr_ = 0x8f19, .enemy_tilesets_ptr = 0x82bf, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x94b9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x81fe, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x94d9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc39bfc), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8142, .enemy_population_ptr_ = 0x8b74, .enemy_tilesets_ptr = 0x8255, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x94f9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8230, .bg_data_ptr = 0xb93b, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x950a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc39db8), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_UpperCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8144, .enemy_population_ptr_ = 0x8002, .enemy_tilesets_ptr = 0x8009, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0x9528, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyOcean_)             , .room_plm_header_ptr = 0x8238, .bg_data_ptr = 0xb7f2, .room_setup_code = FUNC16(RoomSetup_ScrollingSkyOcean)              , };
    case 0x955f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3acdb), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8154, .enemy_population_ptr_ = 0x8b3e, .enemy_tilesets_ptr = 0x823d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x1, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x823a, .bg_data_ptr = 0xb87e, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x958a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3b1ba), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8156, .enemy_population_ptr_ = 0x8ab8, .enemy_tilesets_ptr = 0x8221, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x1, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x823c, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x95b5: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3bb9b), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8166, .enemy_population_ptr_ = 0x85db, .enemy_tilesets_ptr = 0x8133, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x95d3, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x823e, .bg_data_ptr = 0xb87e, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x95e1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3bcd2), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8168, .enemy_population_ptr_ = 0x8b3b, .enemy_tilesets_ptr = 0x8233, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8246, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x960c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3bd6d), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x816a, .enemy_population_ptr_ = 0x85de, .enemy_tilesets_ptr = 0x8141, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8248, .bg_data_ptr = 0xb8b4, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x9637: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3c145), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x817a, .enemy_population_ptr_ = 0x89df, .enemy_tilesets_ptr = 0x81f3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9657, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8250, .bg_data_ptr = 0xb93b, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x9668: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3c301), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x817c, .enemy_population_ptr_ = 0x89f2, .enemy_tilesets_ptr = 0x81fd, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9686, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x825e, .bg_data_ptr = 0xb899, .room_setup_code = FUNC16(nullsub_134)                              , };
    case 0x969c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3c80c), .tileset_ = kTileSet_0_UpperCrateria              , .music_data_index_ = (uint8)kMusic_UpperCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x818c, .enemy_population_ptr_ = 0x88b6, .enemy_tilesets_ptr = 0x81c1, .layer2_scroll_ =  0x181, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollingSkyOcean_)             , .room_plm_header_ptr = 0x826c, .bg_data_ptr = 0xb80a, .room_setup_code = FUNC16(RoomSetup_ScrollingSkyOcean)              , };
    case 0x9705: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3c998), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_Song2                                 , .room_layer3_fx_ptr_ = 0x8020, .enemy_population_ptr_ = 0x85b2, .enemy_tilesets_ptr = 0x8111, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9729, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ExplodeShakes)                  , .room_plm_header_ptr = 0x830c, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(RoomSetup_AutoDestroyWallAfterEscape)     , };
    case 0x96eb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3c998), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8060, .enemy_population_ptr_ = 0x88c9, .enemy_tilesets_ptr = 0x81d3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9729, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x826e, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x96d1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3c998), .tileset_ = kTileSet_3_OldTourian                 , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x818e, .enemy_population_ptr_ = 0x85e1, .enemy_tilesets_ptr = 0x814f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9729, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x826e, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9787: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3d9f7), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8080, .enemy_population_ptr_ = 0x8427, .enemy_tilesets_ptr = 0x808f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x97a5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x83d0, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x976d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3d9f7), .tileset_ = kTileSet_3_OldTourian                 , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x819e, .enemy_population_ptr_ = 0x8a15, .enemy_tilesets_ptr = 0x820f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x97a5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x83b6, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x97e0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3df23), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8090, .enemy_population_ptr_ = 0x8b61, .enemy_tilesets_ptr = 0x824b, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0x9800, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x83f6, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x97c6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3df23), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_EmptyCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x81ae, .enemy_population_ptr_ = 0x8b61, .enemy_tilesets_ptr = 0x824b, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0x9800, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x83f6, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x984f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e0d0), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8030, .enemy_population_ptr_ = 0x8ed3, .enemy_tilesets_ptr = 0x82a3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr = 0x986b, .main_code_ptr = FUNC16(RoomCode_ExplodeShakes)                  , .room_plm_header_ptr = 0x8412, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(RoomSetup_TurnWallIntoShotblocks)         , };
    case 0x9835: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e0d0), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x81be, .enemy_population_ptr_ = 0x84ed, .enemy_tilesets_ptr = 0x80b3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x83fe, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x981b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e0d0), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x81be, .enemy_population_ptr_ = 0x84ed, .enemy_tilesets_ptr = 0x80b3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x83fe, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x98c4: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e16e), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_Song2                                 , .room_layer3_fx_ptr_ = 0x8040, .enemy_population_ptr_ = 0x8f16, .enemy_tilesets_ptr = 0x82b5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ExplodeShakes)                  , .room_plm_header_ptr = 0x8428, .bg_data_ptr = 0xb8ea, .room_setup_code = FUNC16(nullsub_132)                              , };
    case 0x98aa: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e16e), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x81c0, .enemy_population_ptr_ = 0x8364, .enemy_tilesets_ptr = 0x807d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8420, .bg_data_ptr = 0xb8ea, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9890: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e16e), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x81c0, .enemy_population_ptr_ = 0x8364, .enemy_tilesets_ptr = 0x807d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8420, .bg_data_ptr = 0xb8ea, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x98ef: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e232), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81c2, .enemy_population_ptr_ = 0x8b87, .enemy_tilesets_ptr = 0x825f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8430, .bg_data_ptr = 0xb920, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x991a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e2fc), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81c2, .enemy_population_ptr_ = 0x8108, .enemy_tilesets_ptr = 0x8031, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8432, .bg_data_ptr = 0xb8cf, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9945: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3e985), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x81c2, .enemy_population_ptr_ = 0x8573, .enemy_tilesets_ptr = 0x80d3, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0x9965, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x843a, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9976: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3eb35), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x81c2, .enemy_population_ptr_ = 0x8bca, .enemy_tilesets_ptr = 0x8271, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8442, .bg_data_ptr = 0xb8cf, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x99a1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce86bd), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81c2, .enemy_population_ptr_ = 0x85a9, .enemy_tilesets_ptr = 0x80eb, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8444, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x99ca: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3ee60), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x81c2, .enemy_population_ptr_ = 0x8500, .enemy_tilesets_ptr = 0x80c1, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr = 0x99ec, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x844c, .bg_data_ptr = 0xb956, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9a06: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc3f4d3), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81c4, .enemy_population_ptr_ = 0x8870, .enemy_tilesets_ptr = 0x81a5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9a24, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8478, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9a70: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4811e), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x80a0, .enemy_population_ptr_ = 0x819b, .enemy_tilesets_ptr = 0x8043, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9a8e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8482, .bg_data_ptr = 0xb956, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9a56: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4811e), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81d4, .enemy_population_ptr_ = 0x81fe, .enemy_tilesets_ptr = 0x8055, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9a8e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8480, .bg_data_ptr = 0xb956, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9abc: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc48232), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x80b0, .enemy_population_ptr_ = 0x85af, .enemy_tilesets_ptr = 0x8107, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9ad8, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8486, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9aa2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc48232), .tileset_ = kTileSet_2_LowerCrateria              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81e4, .enemy_population_ptr_ = 0x8586, .enemy_tilesets_ptr = 0x80dd, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9ad8, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8484, .bg_data_ptr = 0xb905, .room_setup_code = FUNC16(nullsub_135)                              , };
    case 0x9ae6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4f1ce), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8204, .enemy_population_ptr_ = 0x997a, .enemy_tilesets_ptr = 0x8541, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0x9b16, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x848e, .bg_data_ptr = 0xba37, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9b68: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc58bd5), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8214, .enemy_population_ptr_ = 0x9a2d, .enemy_tilesets_ptr = 0x8557, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9b86, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x84d8, .bg_data_ptr = 0xbabe, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9baa: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc59642), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8224, .enemy_population_ptr_ = 0x8f7c, .enemy_tilesets_ptr = 0x82d5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x84ec, .bg_data_ptr = 0xba88, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9bd5: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc59755), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8226, .enemy_population_ptr_ = 0x9a40, .enemy_tilesets_ptr = 0x8565, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9bf3, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x84f4, .bg_data_ptr = 0xbaa3, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9c14: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc59b00), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8228, .enemy_population_ptr_ = 0x9f38, .enemy_tilesets_ptr = 0x85fd, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9c30, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8526, .bg_data_ptr = 0xba6d, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9c42: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce83c3), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x822a, .enemy_population_ptr_ = 0x8fbf, .enemy_tilesets_ptr = 0x82e7, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8540, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9c6b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc59cac), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x822c, .enemy_population_ptr_ = 0x96e2, .enemy_tilesets_ptr = 0x84c9, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8548, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9c96: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce8cb3), .tileset_ = kTileSet_24_YellowRefillRoom          , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x823c, .enemy_population_ptr_ = 0x8fc2, .enemy_tilesets_ptr = 0x82f1, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0x9cb2, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8550, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9cc0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5a15f), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x823e, .enemy_population_ptr_ = 0x9d5c, .enemy_tilesets_ptr = 0x85b9, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0x9ce0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ScrollRightDachora)             , .room_plm_header_ptr = 0x8558, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9d26: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5b54d), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x824e, .enemy_population_ptr_ = 0x953e, .enemy_tilesets_ptr = 0x8429, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9d52, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x85e4, .bg_data_ptr = 0xbb45, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9da9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5cba7), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x825e, .enemy_population_ptr_ = 0x8fc5, .enemy_tilesets_ptr = 0x82fb, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8634, .bg_data_ptr = 0xba52, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9df3: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5ce34), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x826e, .enemy_population_ptr_ = 0xa0fd, .enemy_tilesets_ptr = 0x8663, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x1, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8642, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9dd9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5ce34), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_MinibossFight , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x826e, .enemy_population_ptr_ = 0xa0fd, .enemy_tilesets_ptr = 0x8663, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x1, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8642, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9e1e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5d18f), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x827e, .enemy_population_ptr_ = 0x961d, .enemy_tilesets_ptr = 0x846f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9e3c, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x864a, .bg_data_ptr = 0xbaa3, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9e5f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5d559), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x828e, .enemy_population_ptr_ = 0x9cb9, .enemy_tilesets_ptr = 0x85a7, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9e7f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8664, .bg_data_ptr = 0xbad9, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9ecb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5ded5), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x81f4, .enemy_population_ptr_ = 0x9326, .enemy_tilesets_ptr = 0x83b5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9eed, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x86e6, .bg_data_ptr = 0xbaf4, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x9eb1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5ded5), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_EmptyCrateria , .music_track_index_ = kMusic_Song2                                 , .room_layer3_fx_ptr_ = 0x8290, .enemy_population_ptr_ = 0x93ac, .enemy_tilesets_ptr = 0x83d1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9eed, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x867e, .bg_data_ptr = 0xbaf4, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9f3d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5e63a), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81f4, .enemy_population_ptr_ = 0x918d, .enemy_tilesets_ptr = 0x8377, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9f5d, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8754, .bg_data_ptr = 0xbabe, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x9f23: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5e63a), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x82a0, .enemy_population_ptr_ = 0x9bc6, .enemy_tilesets_ptr = 0x8595, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9f5d, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8754, .bg_data_ptr = 0xbabe, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9f90: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5e86f), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x81f4, .enemy_population_ptr_ = 0x9200, .enemy_tilesets_ptr = 0x8389, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9fae, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x878c, .bg_data_ptr = 0xbaf4, .room_setup_code = FUNC16(nullsub_133)                              , };
    case 0x9f76: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5e86f), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x82b0, .enemy_population_ptr_ = 0x966f, .enemy_tilesets_ptr = 0x84b7, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0x9fae, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x878c, .bg_data_ptr = 0xbaf4, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9fc7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5ecae), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x82c0, .enemy_population_ptr_ = 0x92a3, .enemy_tilesets_ptr = 0x83a3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87a6, .bg_data_ptr = 0xba52, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0x9ff2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5ef71), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x82d0, .enemy_population_ptr_ = 0x9735, .enemy_tilesets_ptr = 0x84d7, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xa010, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87ae, .bg_data_ptr = 0xba52, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa01e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5f057), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x82d2, .enemy_population_ptr_ = 0x9778, .enemy_tilesets_ptr = 0x84e5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa040, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87b0, .bg_data_ptr = 0xba52, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa05e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5f43e), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x82e2, .enemy_population_ptr_ = 0x9028, .enemy_tilesets_ptr = 0x8309, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xa07a, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87d0, .bg_data_ptr = 0xba52, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa088: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce89b6), .tileset_ = kTileSet_23_BlueRefillRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x82f2, .enemy_population_ptr_ = 0x902b, .enemy_tilesets_ptr = 0x8313, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87d8, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa0b1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5f4c9), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x82f4, .enemy_population_ptr_ = 0x902e, .enemy_tilesets_ptr = 0x8321, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xa0cf, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87e0, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa0df: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5f778), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8304, .enemy_population_ptr_ = 0x911a, .enemy_tilesets_ptr = 0x8361, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr = 0xa0fd, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x87e8, .bg_data_ptr = 0xbaa3, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa114: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5fd50), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8314, .enemy_population_ptr_ = 0x9eb2, .enemy_tilesets_ptr = 0x85e5, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8802, .bg_data_ptr = 0xbabe, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa13d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc5fe1b), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8324, .enemy_population_ptr_ = 0x97fb, .enemy_tilesets_ptr = 0x84f7, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x880a, .bg_data_ptr = 0xbaa3, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa168: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc681c2), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8334, .enemy_population_ptr_ = 0x90c4, .enemy_tilesets_ptr = 0x8345, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8824, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa191: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8336, .enemy_population_ptr_ = 0x953b, .enemy_tilesets_ptr = 0x841f, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x882c, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa1ba: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc68318), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8338, .enemy_population_ptr_ = 0x9505, .enemy_tilesets_ptr = 0x8407, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8834, .bg_data_ptr = 0xbaf4, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa1e5: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc68437), .tileset_ = kTileSet_6_GreenBrinstar_BlueBrinstar , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8348, .enemy_population_ptr_ = 0x9538, .enemy_tilesets_ptr = 0x8415, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8836, .bg_data_ptr = 0xbaf4, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa20e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x834a, .enemy_population_ptr_ = 0x9617, .enemy_tilesets_ptr = 0x845b, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8844, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa237: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_GreenBrinstar , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x834c, .enemy_population_ptr_ = 0x95e1, .enemy_tilesets_ptr = 0x843f, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x884c, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_136)                              , };
    case 0xa260: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc684ee), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x834e, .enemy_population_ptr_ = 0x9452, .enemy_tilesets_ptr = 0x83f1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa284, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8854, .bg_data_ptr = 0xbb7b, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa2a0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc691e3), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x835e, .enemy_population_ptr_ = 0x9b13, .enemy_tilesets_ptr = 0x857f, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xa2be, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x886e, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa2db: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc69bf9), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x836e, .enemy_population_ptr_ = 0x9f3b, .enemy_tilesets_ptr = 0x8607, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8876, .bg_data_ptr = 0xbc38, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa304: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc69d70), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8370, .enemy_population_ptr_ = 0x9e2f, .enemy_tilesets_ptr = 0x85d3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x887e, .bg_data_ptr = 0xbbcc, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa32f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc69f4b), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8380, .enemy_population_ptr_ = 0xa057, .enemy_tilesets_ptr = 0x863f, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xa357, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8880, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa389: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6b31f), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8390, .enemy_population_ptr_ = 0x90c7, .enemy_tilesets_ptr = 0x834f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa3a5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x88be, .bg_data_ptr = 0xbbe7, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa3bb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6b58c), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x83a0, .enemy_population_ptr_ = 0x9f61, .enemy_tilesets_ptr = 0x861f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa3d7, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x88d8, .bg_data_ptr = 0xbcec, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa3ea: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6b739), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x83b0, .enemy_population_ptr_ = 0xa110, .enemy_tilesets_ptr = 0x8671, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x891c, .bg_data_ptr = 0xbbe7, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa415: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6b91c), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x83c0, .enemy_population_ptr_ = 0x95e4, .enemy_tilesets_ptr = 0x8449, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa435, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x891e, .bg_data_ptr = 0xbc02, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa454: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6bcc7), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x83d0, .enemy_population_ptr_ = 0x961a, .enemy_tilesets_ptr = 0x8465, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa470, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x896e, .bg_data_ptr = 0xbcec, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa47e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6bd83), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x83d2, .enemy_population_ptr_ = 0x941f, .enemy_tilesets_ptr = 0x83e3, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xa49e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8976, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa4be: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6c469), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x83d2, .enemy_population_ptr_ = 0x988e, .enemy_tilesets_ptr = 0x850d, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8996, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa4e7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6c630), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x83d2, .enemy_population_ptr_ = 0x98f7, .enemy_tilesets_ptr = 0x8533, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xa507, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x89a4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa54d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6cdb9), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_BossFight2    , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x83e2, .enemy_population_ptr_ = 0xa0ba, .enemy_tilesets_ptr = 0x8651, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x89f4, .bg_data_ptr = 0xbc6e, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa533: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6cdb9), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_BossFight2    , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x83e2, .enemy_population_ptr_ = 0xa0ba, .enemy_tilesets_ptr = 0x8651, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x89f4, .bg_data_ptr = 0xbc6e, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa578: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6d2cb), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x83f2, .enemy_population_ptr_ = 0x9fa4, .enemy_tilesets_ptr = 0x862d, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xa598, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a02, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa5cb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6d620), .tileset_ = kTileSet_26_KraidsRoom                , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x83f4, .enemy_population_ptr_ = 0x9eb5, .enemy_tilesets_ptr = 0x85ef, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xa5e9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a2e, .bg_data_ptr = 0xb840, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa5b1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6d620), .tileset_ = kTileSet_26_KraidsRoom                , .music_data_index_ = (uint8)kMusic_BossFight2    , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x83f4, .enemy_population_ptr_ = 0x9eb5, .enemy_tilesets_ptr = 0x85ef, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xa5e9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a2e, .bg_data_ptr = 0xb815, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa5fa: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6d88d), .tileset_ = kTileSet_8_PreTourianEntranceCorrdior , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_PreStatueHall_PreRidleyFight_GameOver , .room_layer3_fx_ptr_ = 0x83f6, .enemy_population_ptr_ = 0x9f5e, .enemy_tilesets_ptr = 0x8615, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a3c, .bg_data_ptr = 0xbca4, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa625: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce89b6), .tileset_ = kTileSet_23_BlueRefillRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8406, .enemy_population_ptr_ = 0x9660, .enemy_tilesets_ptr = 0x8485, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a3e, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa64e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcea201), .tileset_ = kTileSet_24_YellowRefillRoom          , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8408, .enemy_population_ptr_ = 0x9663, .enemy_tilesets_ptr = 0x848f, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a46, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_137)                              , };
    case 0xa677: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce9be9), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_LowerCrateria , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x840a, .enemy_population_ptr_ = 0x9081, .enemy_tilesets_ptr = 0x8333, .layer2_scroll_ =  0x181, .rdf_scroll_ptr = 0xa697, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a54, .bg_data_ptr = 0xbb60, .room_setup_code = FUNC16(RoomSetup_RunStatueUnlockAnims)           , };
    case 0xa6ae: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6dee0), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x841a, .enemy_population_ptr_ = 0x98e4, .enemy_tilesets_ptr = 0x8529, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa6d0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8a5c, .bg_data_ptr = 0xbc53, .room_setup_code = FUNC16(nullsub_138)                              , };
    case 0xa6ef: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6e355), .tileset_ = kTileSet_7_RedBrinstar_KraidsLair     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x842a, .enemy_population_ptr_ = 0x9666, .enemy_tilesets_ptr = 0x8499, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8aca, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_138)                              , };
    case 0xa718: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x842c, .enemy_population_ptr_ = 0x93a9, .enemy_tilesets_ptr = 0x83c7, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8ad2, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_138)                              , };
    case 0xa741: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x842e, .enemy_population_ptr_ = 0x9669, .enemy_tilesets_ptr = 0x84a3, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8ada, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_138)                              , };
    case 0xa76a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6e4a4), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8430, .enemy_population_ptr_ = 0xb45b, .enemy_tilesets_ptr = 0x89f3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8ae2, .bg_data_ptr = 0xbe3f, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa795: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6e5f5), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8440, .enemy_population_ptr_ = 0xb544, .enemy_tilesets_ptr = 0x8a25, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8ae4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa7c0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6ecb9), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8450, .enemy_population_ptr_ = 0xaf87, .enemy_tilesets_ptr = 0x892b, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8af2, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa7eb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6f2e1), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8460, .enemy_population_ptr_ = 0xb9d8, .enemy_tilesets_ptr = 0x8aed, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8afa, .bg_data_ptr = 0xbee1, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa822: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc6f8c1), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8470, .enemy_population_ptr_ = 0xa332, .enemy_tilesets_ptr = 0x86d5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa844, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8b14, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa872: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc782ed), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8480, .enemy_population_ptr_ = 0xb48e, .enemy_tilesets_ptr = 0x8a01, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8b22, .bg_data_ptr = 0xbe3f, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa89d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc784a3), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8490, .enemy_population_ptr_ = 0xa63c, .enemy_tilesets_ptr = 0x879d, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8b24, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa8c6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc785d6), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x84a0, .enemy_population_ptr_ = 0xb6ad, .enemy_tilesets_ptr = 0x8a5b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa8e6, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8b2c, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa905: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc78a47), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x84b0, .enemy_population_ptr_ = 0xb1f6, .enemy_tilesets_ptr = 0x897d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8b46, .bg_data_ptr = 0xbee1, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa930: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc78cfa), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x84c0, .enemy_population_ptr_ = 0xa9da, .enemy_tilesets_ptr = 0x8845, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xa954, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8b4e, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_139)                              , };
    case 0xa9b9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc79d71), .tileset_ = kTileSet_27_CrocomiresRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x84d0, .enemy_population_ptr_ = 0xbb0e, .enemy_tilesets_ptr = 0x8b11, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xa9d7, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_CrocomireRoomShaking)           , .room_plm_header_ptr = 0x8b9e, .bg_data_ptr = 0xb858, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xa99f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc79d71), .tileset_ = kTileSet_27_CrocomiresRoom            , .music_data_index_ = (uint8)kMusic_BossFight2    , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x84d0, .enemy_population_ptr_ = 0xbb0e, .enemy_tilesets_ptr = 0x8b11, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xa9d7, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_CrocomireRoomShaking)           , .room_plm_header_ptr = 0x8b9e, .bg_data_ptr = 0xb84d, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xa9f2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7a036), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x84e0, .enemy_population_ptr_ = 0xa63f, .enemy_tilesets_ptr = 0x87a7, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8bac, .bg_data_ptr = 0xbe3f, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaa1b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7a18d), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x84f0, .enemy_population_ptr_ = 0xad8f, .enemy_tilesets_ptr = 0x88bf, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xaa39, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8bb4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaa4e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7aa70), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8500, .enemy_population_ptr_ = 0xb3c5, .enemy_tilesets_ptr = 0x89cb, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xaa6c, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8bc8, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaa8f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7aeb3), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8510, .enemy_population_ptr_ = 0xa7bb, .enemy_tilesets_ptr = 0x87df, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xaab1, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8bf4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaac2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8520, .enemy_population_ptr_ = 0xa642, .enemy_tilesets_ptr = 0x87b1, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8bfc, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaaeb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7b28b), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8530, .enemy_population_ptr_ = 0xa639, .enemy_tilesets_ptr = 0x8793, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c04, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xab14: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7b3e7), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8540, .enemy_population_ptr_ = 0xa1d6, .enemy_tilesets_ptr = 0x8695, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xab36, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c0c, .bg_data_ptr = 0xbee1, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xab48: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7b780), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8550, .enemy_population_ptr_ = 0xb4d1, .enemy_tilesets_ptr = 0x8a13, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c14, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xab71: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7bb6b), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8560, .enemy_population_ptr_ = 0xa133, .enemy_tilesets_ptr = 0x8683, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c1c, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xab9c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7becb), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8570, .enemy_population_ptr_ = 0xb11d, .enemy_tilesets_ptr = 0x8953, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xabba, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c2a, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xabdf: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7cd91), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8580, .enemy_population_ptr_ = 0xb67a, .enemy_tilesets_ptr = 0x8a49, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xabfd, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c32, .bg_data_ptr = 0xbee1, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xac0d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7cfcd), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8590, .enemy_population_ptr_ = 0xb3bf, .enemy_tilesets_ptr = 0x89b7, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c34, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xac38: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7d13c), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x85a0, .enemy_population_ptr_ = 0xa964, .enemy_tilesets_ptr = 0x8825, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xac56, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c36, .bg_data_ptr = 0xbee1, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xac67: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7d4fe), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x85b0, .enemy_population_ptr_ = 0xb5e7, .enemy_tilesets_ptr = 0x8a37, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c3e, .bg_data_ptr = 0xbf68, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xac90: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7d66f), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x85c0, .enemy_population_ptr_ = 0xaeb1, .enemy_tilesets_ptr = 0x8907, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xacae, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c4c, .bg_data_ptr = 0xbf83, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xacc0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7d895), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x85d0, .enemy_population_ptr_ = 0xb3d8, .enemy_tilesets_ptr = 0x89d9, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xace8, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c5a, .bg_data_ptr = 0xbf83, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xacfd: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7e08c), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x85e0, .enemy_population_ptr_ = 0xb88f, .enemy_tilesets_ptr = 0x8abb, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c6e, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xad28: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7eaa8), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8600, .enemy_population_ptr_ = 0xb766, .enemy_tilesets_ptr = 0x8a8d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c82, .bg_data_ptr = 0xbe3f, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xad6b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7ec03), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8610, .enemy_population_ptr_ = 0xb81c, .enemy_tilesets_ptr = 0x8aa9, .layer2_scroll_ = 0xc0c0, .rdf_scroll_ptr = 0xad8f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8c8a, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xadba: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc7ff02), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8620, .enemy_population_ptr_ = 0xa8e1, .enemy_tilesets_ptr = 0x880b, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xadda, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8cb0, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xadeb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc88532), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x8630, .enemy_population_ptr_ = 0xa4ee, .enemy_tilesets_ptr = 0x871d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8cca, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xae14: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8865c), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8640, .enemy_population_ptr_ = 0xb733, .enemy_tilesets_ptr = 0x8a7b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8cd2, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xae3f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc88953), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8650, .enemy_population_ptr_ = 0xbb34, .enemy_tilesets_ptr = 0x8b29, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xae5d, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8cd4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xae81: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8943a), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8670, .enemy_population_ptr_ = 0xb995, .enemy_tilesets_ptr = 0x8adf, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xaea3, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d1e, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaec1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc89d5d), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8680, .enemy_population_ptr_ = 0xac53, .enemy_tilesets_ptr = 0x8887, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d56, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaeec: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc89fe3), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8690, .enemy_population_ptr_ = 0xaea8, .enemy_tilesets_ptr = 0x88e9, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xaf0c, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d58, .bg_data_ptr = 0xbf68, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaf21: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8a2cf), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x86a0, .enemy_population_ptr_ = 0xad09, .enemy_tilesets_ptr = 0x88a3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d7e, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaf4c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8aa89), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x86b0, .enemy_population_ptr_ = 0xa544, .enemy_tilesets_ptr = 0x873d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xaf6e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d80, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xaf7f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8abed), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x86c0, .enemy_population_ptr_ = 0xbbd7, .enemy_tilesets_ptr = 0x8b3b, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xaf9f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d88, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xafb0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8b15b), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x86d0, .enemy_population_ptr_ = 0xa6a8, .enemy_tilesets_ptr = 0x87c9, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d96, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xafdb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8b4f9), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x86f0, .enemy_population_ptr_ = 0xb32c, .enemy_tilesets_ptr = 0x89a5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d98, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb008: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8b853), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8700, .enemy_population_ptr_ = 0xa3f5, .enemy_tilesets_ptr = 0x86ef, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d9a, .bg_data_ptr = 0xbec6, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb033: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce8fa6), .tileset_ = kTileSet_23_BlueRefillRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8710, .enemy_population_ptr_ = 0xa55a, .enemy_tilesets_ptr = 0x8751, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8d9c, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb05e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8b9cf), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8720, .enemy_population_ptr_ = 0xa2df, .enemy_tilesets_ptr = 0x86c7, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8da4, .bg_data_ptr = 0xbf68, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb087: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8bb21), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8730, .enemy_population_ptr_ = 0xb912, .enemy_tilesets_ptr = 0x8acd, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xb0a5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8da6, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb0c1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce83c3), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8740, .enemy_population_ptr_ = 0xa55d, .enemy_tilesets_ptr = 0x875b, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8dd8, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb0ea: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8750, .enemy_population_ptr_ = 0xb3c2, .enemy_tilesets_ptr = 0x89c1, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8de0, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb113: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8bde8), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8760, .enemy_population_ptr_ = 0xa645, .enemy_tilesets_ptr = 0x87bb, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr = 0xb131, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8de8, .bg_data_ptr = 0xbe3f, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb146: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8c165), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x8762, .enemy_population_ptr_ = 0xa967, .enemy_tilesets_ptr = 0x8833, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr = 0xb164, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8dea, .bg_data_ptr = 0xbee1, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb174: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce9ef6), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8764, .enemy_population_ptr_ = 0xb1f0, .enemy_tilesets_ptr = 0x8969, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8dec, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb19f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8766, .enemy_population_ptr_ = 0xb1f3, .enemy_tilesets_ptr = 0x8973, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8df4, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_140)                              , };
    case 0xb1c8: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_UpperNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x8768, .enemy_population_ptr_ = 0xbb31, .enemy_tilesets_ptr = 0x8b1f, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xb1e4, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8dfc, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xb1f2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8c4d3), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x876a, .enemy_population_ptr_ = 0xa23c, .enemy_tilesets_ptr = 0x86b1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb210, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8e04, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb243: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8d59c), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x878a, .enemy_population_ptr_ = 0xafea, .enemy_tilesets_ptr = 0x893d, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr = 0xb265, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8e12, .bg_data_ptr = 0xbf17, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb2af: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8e09d), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x879a, .enemy_population_ptr_ = 0xb720, .enemy_tilesets_ptr = 0x8a6d, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xb2cd, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8e3e, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb295: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8e09d), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x879a, .enemy_population_ptr_ = 0xb720, .enemy_tilesets_ptr = 0x8a6d, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xb2cd, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8e3e, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb2e7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8e900), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x87aa, .enemy_population_ptr_ = 0xa48b, .enemy_tilesets_ptr = 0x870f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8e82, .bg_data_ptr = 0xbf17, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb312: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce98dc), .tileset_ = kTileSet_23_BlueRefillRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x87ba, .enemy_population_ptr_ = 0xa623, .enemy_tilesets_ptr = 0x8777, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8e90, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb35a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8ebfd), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x87bc, .enemy_population_ptr_ = 0xa626, .enemy_tilesets_ptr = 0x8781, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr = 0xb378, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_RidleyRoomShaking)              , .room_plm_header_ptr = 0x8e98, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb340: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8ebfd), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_PreStatueHall_PreRidleyFight_GameOver , .room_layer3_fx_ptr_ = 0x87bc, .enemy_population_ptr_ = 0xa626, .enemy_tilesets_ptr = 0x8781, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr = 0xb378, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_RidleyRoomShaking)              , .room_plm_header_ptr = 0x8e98, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb387: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8edce), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x87cc, .enemy_population_ptr_ = 0xb769, .enemy_tilesets_ptr = 0x8a97, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8ea6, .bg_data_ptr = 0xbf4d, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb3b2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8f01f), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x87dc, .enemy_population_ptr_ = 0xa4f1, .enemy_tilesets_ptr = 0x8727, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb3d6, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8eba, .bg_data_ptr = 0xbeab, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb417: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8f58b), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x87fc, .enemy_population_ptr_ = 0xa560, .enemy_tilesets_ptr = 0x8765, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb435, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8ed6, .bg_data_ptr = 0xbf68, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb464: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc8fcc5), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x880c, .enemy_population_ptr_ = 0xad6c, .enemy_tilesets_ptr = 0x88b1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8f38, .bg_data_ptr = 0xbf17, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb48f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc98222), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x881c, .enemy_population_ptr_ = 0xaa8d, .enemy_tilesets_ptr = 0x885f, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8f3a, .bg_data_ptr = 0xbf4d, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb4ba: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc984d3), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x882c, .enemy_population_ptr_ = 0xa82e, .enemy_tilesets_ptr = 0x87f5, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb4da, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8f3c, .bg_data_ptr = 0xbefc, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb4f2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9899f), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x883c, .enemy_population_ptr_ = 0xaef4, .enemy_tilesets_ptr = 0x891d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8f7a, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb51d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc994ba), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x885c, .enemy_population_ptr_ = 0xae52, .enemy_tilesets_ptr = 0x88d1, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb53d, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8f7c, .bg_data_ptr = 0xbf68, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb567: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc99ce2), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x886c, .enemy_population_ptr_ = 0xaea5, .enemy_tilesets_ptr = 0x88df, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8fd2, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb592: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc99e7b), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x887c, .enemy_population_ptr_ = 0xa428, .enemy_tilesets_ptr = 0x86fd, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb5b4, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x8fda, .bg_data_ptr = 0xbe5a, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb5e2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9a88c), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x888c, .enemy_population_ptr_ = 0xb259, .enemy_tilesets_ptr = 0x898b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb600, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x9036, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb638: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9b1c7), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x889c, .enemy_population_ptr_ = 0xa219, .enemy_tilesets_ptr = 0x86a3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x90c8, .bg_data_ptr = 0xbf4d, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb663: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9b4ab), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x88ac, .enemy_population_ptr_ = 0xba4b, .enemy_tilesets_ptr = 0x8afb, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xb681, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x90d0, .bg_data_ptr = 0xbf68, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb6a5: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9c30d), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x88bc, .enemy_population_ptr_ = 0xaeab, .enemy_tilesets_ptr = 0x88f3, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x9108, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb6ce: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9c428), .tileset_ = kTileSet_9_HeatedNorfair              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x88cc, .enemy_population_ptr_ = 0xaeae, .enemy_tilesets_ptr = 0x88fd, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x9110, .bg_data_ptr = 0xbf32, .room_setup_code = FUNC16(nullsub_141)                              , };
    case 0xb6fb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9c706), .tileset_ = kTileSet_10_UnheatedNorfair           , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x88dc, .enemy_population_ptr_ = 0xab80, .enemy_tilesets_ptr = 0x8871, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xb71b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x9118, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xb74e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_LowerNorfair  , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x88ec, .enemy_population_ptr_ = 0xa557, .enemy_tilesets_ptr = 0x8747, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0x918c, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xc9ba: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc48322), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9ac2, .enemy_population_ptr_ = 0xc1ae, .enemy_tilesets_ptr = 0x8c01, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xc9da, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2d1, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xc9a0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc48322), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9ba4, .enemy_population_ptr_ = 0xbe93, .enemy_tilesets_ptr = 0x8b87, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xc9da, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc215, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xca34: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc49d2e), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9ad2, .enemy_population_ptr_ = 0xc1a8, .enemy_tilesets_ptr = 0x8bed, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2fd, .bg_data_ptr = 0xe117, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xca1a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc49d2e), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9bb4, .enemy_population_ptr_ = 0xc3e6, .enemy_tilesets_ptr = 0x8c6d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc22f, .bg_data_ptr = 0xe117, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xca7e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4a2e7), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9ae2, .enemy_population_ptr_ = 0xbfe6, .enemy_tilesets_ptr = 0x8b99, .layer2_scroll_ = 0xffc1, .rdf_scroll_ptr = 0xca9e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2ff, .bg_data_ptr = 0xe168, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xca64: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc49eae), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9bc4, .enemy_population_ptr_ = 0xc6f2, .enemy_tilesets_ptr = 0x8ca9, .layer2_scroll_ = 0xffc1, .rdf_scroll_ptr = 0xca9e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc231, .bg_data_ptr = 0xe168, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcada: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4a720), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9af2, .enemy_population_ptr_ = 0xc5e9, .enemy_tilesets_ptr = 0x8c7b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc319, .bg_data_ptr = 0xe1b9, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcac0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4a720), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9bd4, .enemy_population_ptr_ = 0xc1e1, .enemy_tilesets_ptr = 0x8c13, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc245, .bg_data_ptr = 0xe1b9, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcb22: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4bdc0), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9b02, .enemy_population_ptr_ = 0xcd17, .enemy_tilesets_ptr = 0x8d2b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcb4a, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc247, .bg_data_ptr = 0xe19e, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcb08: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4a9ac), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9be4, .enemy_population_ptr_ = 0xbca0, .enemy_tilesets_ptr = 0x8b6d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcb4a, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc247, .bg_data_ptr = 0xe19e, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcbb7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4d187), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9b12, .enemy_population_ptr_ = 0xcbae, .enemy_tilesets_ptr = 0x8cf9, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc321, .bg_data_ptr = 0xe14d, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcb9d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4d187), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9bf4, .enemy_population_ptr_ = 0xc1a2, .enemy_tilesets_ptr = 0x8bd9, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc27f, .bg_data_ptr = 0xe14d, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcc01: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4d3ee), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9b22, .enemy_population_ptr_ = 0xcb3b, .enemy_tilesets_ptr = 0x8ceb, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcc21, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc323, .bg_data_ptr = 0xe19e, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcbe7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4d3ee), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9c04, .enemy_population_ptr_ = 0xc1ab, .enemy_tilesets_ptr = 0x8bf7, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcc21, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc281, .bg_data_ptr = 0xe19e, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcc53: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4d883), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9b32, .enemy_population_ptr_ = 0xbc4d, .enemy_tilesets_ptr = 0x8b5b, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc337, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcc39: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4d883), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9c14, .enemy_population_ptr_ = 0xc1e7, .enemy_tilesets_ptr = 0x8c27, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc28f, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_142)                              , };
    case 0xcc9b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e14e), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9b42, .enemy_population_ptr_ = 0xc139, .enemy_tilesets_ptr = 0x8baf, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr = 0xccbb, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc33f, .bg_data_ptr = 0xe14d, .room_setup_code = FUNC16(RoomCode_SpawnPrePhantoonRoomEnemyProj)   , };
    case 0xcc81: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e14e), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9c24, .enemy_population_ptr_ = 0xc283, .enemy_tilesets_ptr = 0x8c5b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xccbb, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc291, .bg_data_ptr = 0xe14d, .room_setup_code = FUNC16(RoomCode_SpawnPrePhantoonRoomEnemyProj)   , };
    case 0xccf7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce83c3), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9b52, .enemy_population_ptr_ = 0xc19c, .enemy_tilesets_ptr = 0x8bc5, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc34d, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xccdd: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce83c3), .tileset_ = kTileSet_22_WreckedShipMapRoom_Off    , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9c34, .enemy_population_ptr_ = 0xc1ed, .enemy_tilesets_ptr = 0x8c3b, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2b1, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xcd3f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e58c), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9b62, .enemy_population_ptr_ = 0xc1e4, .enemy_tilesets_ptr = 0x8c1d, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xcd5b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2b3, .bg_data_ptr = 0xe113, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xcd25: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e58c), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_BossFight2    , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9c44, .enemy_population_ptr_ = 0xccd4, .enemy_tilesets_ptr = 0x8d1d, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xcd5b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2b3, .bg_data_ptr = 0xe0fd, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xcd88: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e6a5), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9b64, .enemy_population_ptr_ = 0xbc3a, .enemy_tilesets_ptr = 0x8b4d, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcda6, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc355, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xcd6e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e6a5), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9c54, .enemy_population_ptr_ = 0xc1a5, .enemy_tilesets_ptr = 0x8be3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcda6, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2bb, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xcdd4: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e94e), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9b74, .enemy_population_ptr_ = 0xc69f, .enemy_tilesets_ptr = 0x8c9b, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcdf0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc357, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xcdba: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4e94e), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9c64, .enemy_population_ptr_ = 0xc19f, .enemy_tilesets_ptr = 0x8bcf, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xcdf0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2bd, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xce1d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4ed98), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9b84, .enemy_population_ptr_ = 0xcc51, .enemy_tilesets_ptr = 0x8d07, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xce39, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc35f, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xce03: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4ea8f), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9c74, .enemy_population_ptr_ = 0xc8c5, .enemy_tilesets_ptr = 0x8cbf, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xce39, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2bf, .bg_data_ptr = 0xe19e, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xce6c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4f0a1), .tileset_ = kTileSet_4_WreckedShip_On             , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9b94, .enemy_population_ptr_ = 0xc280, .enemy_tilesets_ptr = 0x8c51, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc36d, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xce52: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc4f0a1), .tileset_ = kTileSet_5_WreckedShip_Off            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9c74, .enemy_population_ptr_ = 0xc1ea, .enemy_tilesets_ptr = 0x8c31, .layer2_scroll_ =  0x101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2c7, .bg_data_ptr = 0xe183, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xceb6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9b94, .enemy_population_ptr_ = 0xc69c, .enemy_tilesets_ptr = 0x8c91, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2c9, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_143)                              , };
    case 0xce9c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_22_WreckedShipMapRoom_Off    , .music_data_index_ = (uint8)kMusic_WreckedShip   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9c74, .enemy_population_ptr_ = 0xca78, .enemy_tilesets_ptr = 0x8cd9, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc2c7, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xcedf: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9c84, .enemy_population_ptr_ = 0xd526, .enemy_tilesets_ptr = 0x8e74, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc375, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xcf27: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9e129), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9c94, .enemy_population_ptr_ = 0xd529, .enemy_tilesets_ptr = 0x8e7e, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xcf49, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc37d, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xcf0d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9db52), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9c94, .enemy_population_ptr_ = 0xd529, .enemy_tilesets_ptr = 0x8e7e, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xcf49, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc37d, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xcf61: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9e6ae), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9ca4, .enemy_population_ptr_ = 0xd53c, .enemy_tilesets_ptr = 0x8e8c, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xcf7f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc3df, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xcf8d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9e809), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_RedBrinstar   , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9cb4, .enemy_population_ptr_ = 0xd53f, .enemy_tilesets_ptr = 0x8e96, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xcfad, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc3e1, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xcfd6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xc9f225), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9cc4, .enemy_population_ptr_ = 0xde6d, .enemy_tilesets_ptr = 0x903a, .layer2_scroll_ = 0xc0c0, .rdf_scroll_ptr = 0xcffa, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc42b, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd024: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xca8eff), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9cd4, .enemy_population_ptr_ = 0xe07f, .enemy_tilesets_ptr = 0x909e, .layer2_scroll_ = 0xc0c0, .rdf_scroll_ptr = 0xd046, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc445, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd062: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcaa113), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9ce4, .enemy_population_ptr_ = 0xd5e2, .enemy_tilesets_ptr = 0x8ea8, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd07e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc47d, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd097: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcaaf99), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9cf4, .enemy_population_ptr_ = 0xd635, .enemy_tilesets_ptr = 0x8eb6, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xd0b5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc48b, .bg_data_ptr = 0xe248, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd0c6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcab24f), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d04, .enemy_population_ptr_ = 0xce6a, .enemy_tilesets_ptr = 0x8d41, .layer2_scroll_ = 0xc0c0, .rdf_scroll_ptr = 0xd0ec, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc499, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd111: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcace42), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9d14, .enemy_population_ptr_ = 0xd3aa, .enemy_tilesets_ptr = 0x8e2c, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd12f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc49b, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd148: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcad474), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d24, .enemy_population_ptr_ = 0xcf90, .enemy_tilesets_ptr = 0x8d65, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd164, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc4a9, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd17a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcadbc8), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d34, .enemy_population_ptr_ = 0xd698, .enemy_tilesets_ptr = 0x8ec4, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd198, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc4bd, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd1b0: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcae458), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0x9d44, .enemy_population_ptr_ = 0xcfc3, .enemy_tilesets_ptr = 0x8d77, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd1d0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc4ef, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd1ea: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcaf59c), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d54, .enemy_population_ptr_ = 0xd75b, .enemy_tilesets_ptr = 0x8ed6, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd20a, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc503, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd229: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcb83db), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9d64, .enemy_population_ptr_ = 0xde17, .enemy_tilesets_ptr = 0x901a, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd24b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc53b, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd25f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcb883a), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d74, .enemy_population_ptr_ = 0xd7ee, .enemy_tilesets_ptr = 0x8eec, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd27d, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc54f, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd28b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcb89e0), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d84, .enemy_population_ptr_ = 0xd801, .enemy_tilesets_ptr = 0x8efa, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd2a9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc551, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd2b7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcb8bd4), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9d94, .enemy_population_ptr_ = 0xd3ed, .enemy_tilesets_ptr = 0x8e42, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd2d3, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc553, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd2e6: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcb9792), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9da4, .enemy_population_ptr_ = 0xd864, .enemy_tilesets_ptr = 0x8f0c, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd304, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc561, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd318: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcba0d0), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9db4, .enemy_population_ptr_ = 0xd006, .enemy_tilesets_ptr = 0x8d85, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd33a, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc563, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd34d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcba878), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9dc4, .enemy_population_ptr_ = 0xd957, .enemy_tilesets_ptr = 0x8f22, .layer2_scroll_ =   0xe0, .rdf_scroll_ptr = 0xd36f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc571, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd394: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbc64f), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9dd4, .enemy_population_ptr_ = 0xdd9b, .enemy_tilesets_ptr = 0x8fe6, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd3b2, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc57f, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd3c3: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce86bd), .tileset_ = kTileSet_21_MapRoom_TourianEntrance   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9de4, .enemy_population_ptr_ = 0xde14, .enemy_tilesets_ptr = 0x9010, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc581, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_144)                              , };
    case 0xd3ec: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9df4, .enemy_population_ptr_ = 0xde0e, .enemy_tilesets_ptr = 0x8ffc, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc589, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xd415: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbcd9f), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e04, .enemy_population_ptr_ = 0xda0a, .enemy_tilesets_ptr = 0x8f38, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x1, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_Elevatube)                      , .room_plm_header_ptr = 0xc591, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd440: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbdcf3), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e34, .enemy_population_ptr_ = 0xdf30, .enemy_tilesets_ptr = 0x904c, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd460, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc593, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd46e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbde8f), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e44, .enemy_population_ptr_ = 0xda3d, .enemy_tilesets_ptr = 0x8f52, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc595, .bg_data_ptr = 0xe25a, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd49b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbe472), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e54, .enemy_population_ptr_ = 0xdad0, .enemy_tilesets_ptr = 0x8f60, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd4bb, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc597, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd4cf: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbe899), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e64, .enemy_population_ptr_ = 0xdad3, .enemy_tilesets_ptr = 0x8f6a, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc5db, .bg_data_ptr = 0xe25a, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd4fc: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbec32), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e74, .enemy_population_ptr_ = 0xdf96, .enemy_tilesets_ptr = 0x906c, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd51a, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc5dd, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd52b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbf580), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e84, .enemy_population_ptr_ = 0xdf63, .enemy_tilesets_ptr = 0x905e, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd549, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc5eb, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd55a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcbfec8), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e94, .enemy_population_ptr_ = 0xdb66, .enemy_tilesets_ptr = 0x8f78, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd578, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc5f9, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd587: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcc80b8), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9e94, .enemy_population_ptr_ = 0xdbd9, .enemy_tilesets_ptr = 0x8f86, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd5a5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc5fb, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd5b4: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcc82a8), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9ea4, .enemy_population_ptr_ = 0xd357, .enemy_tilesets_ptr = 0x8e1e, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd5da, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc5fd, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd5f9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcca13b), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9eb4, .enemy_population_ptr_ = 0xdc3c, .enemy_tilesets_ptr = 0x8f94, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc611, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd624: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcca34a), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9ec4, .enemy_population_ptr_ = 0xdc6f, .enemy_tilesets_ptr = 0x8fa2, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd642, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc619, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd653: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccac48), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9ed4, .enemy_population_ptr_ = 0xd453, .enemy_tilesets_ptr = 0x8e5e, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd675, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc61b, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd6a7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccb843), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9ee4, .enemy_population_ptr_ = 0xdce2, .enemy_tilesets_ptr = 0x8fb8, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd6c5, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc6ad, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd6dd: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccbd31), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9ef4, .enemy_population_ptr_ = 0xdd35, .enemy_tilesets_ptr = 0x8fca, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd6f9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc6e5, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd70a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccc22f), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f04, .enemy_population_ptr_ = 0xdd38, .enemy_tilesets_ptr = 0x8fd4, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd726, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc6ed, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd737: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccc9f1), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f14, .enemy_population_ptr_ = 0xd089, .enemy_tilesets_ptr = 0x8d97, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd757, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc6ef, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd772: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9f24, .enemy_population_ptr_ = 0xd10c, .enemy_tilesets_ptr = 0x8da5, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd78e, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc703, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd7bb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcce5b1), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9f34, .enemy_population_ptr_ = 0xd10f, .enemy_tilesets_ptr = 0x8daf, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd7d9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc70b, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd7a1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcce5b1), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f34, .enemy_population_ptr_ = 0xd10f, .enemy_tilesets_ptr = 0x8daf, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xd7d9, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc70b, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd7f1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccee0c), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9f44, .enemy_population_ptr_ = 0xd112, .enemy_tilesets_ptr = 0x8db9, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd813, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc755, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd827: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce9ef6), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_Maridia       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9f54, .enemy_population_ptr_ = 0xd1b5, .enemy_tilesets_ptr = 0x8dcf, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc75d, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd852: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xceab31), .tileset_ = kTileSet_23_BlueRefillRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f64, .enemy_population_ptr_ = 0xd1b8, .enemy_tilesets_ptr = 0x8dd9, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc765, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd87b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccfa8d), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f74, .enemy_population_ptr_ = 0xd1bb, .enemy_tilesets_ptr = 0x8de3, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd897, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc76d, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd8a5: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccfb88), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f74, .enemy_population_ptr_ = 0xd1ee, .enemy_tilesets_ptr = 0x8df1, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd8c3, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc76f, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_145)                              , };
    case 0xd8f1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcd8404), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f84, .enemy_population_ptr_ = 0xd281, .enemy_tilesets_ptr = 0x8dff, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd90f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc771, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_146)                              , };
    case 0xd8d7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xccfd75), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f84, .enemy_population_ptr_ = 0xd281, .enemy_tilesets_ptr = 0x8dff, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr = 0xd90f, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc771, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(RoomCode_SetupShaktoolRoomPlm)            , };
    case 0xd920: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcd8a37), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9f94, .enemy_population_ptr_ = 0xcf2d, .enemy_tilesets_ptr = 0x8d53, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd942, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc773, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_146)                              , };
    case 0xd98a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcd950e), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9fa4, .enemy_population_ptr_ = 0xde5a, .enemy_tilesets_ptr = 0x9028, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd9a8, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc79f, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_146)                              , };
    case 0xd970: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcd950e), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_MinibossFight , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9fa4, .enemy_population_ptr_ = 0xde5a, .enemy_tilesets_ptr = 0x9028, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd9a8, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc79f, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_146)                              , };
    case 0xd9b7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcd991e), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9fb4, .enemy_population_ptr_ = 0xd450, .enemy_tilesets_ptr = 0x8e54, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd9d3, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7a7, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_146)                              , };
    case 0xd9e1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce98dc), .tileset_ = kTileSet_23_BlueRefillRoom            , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9fc4, .enemy_population_ptr_ = 0xde11, .enemy_tilesets_ptr = 0x9006, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xd9fd, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7af, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xda0b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcd9b28), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9fd4, .enemy_population_ptr_ = 0xdfd9, .enemy_tilesets_ptr = 0x907a, .layer2_scroll_ = 0xc000, .rdf_scroll_ptr = 0xda29, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7b7, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xda38: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcda00d), .tileset_ = kTileSet_12_SandyMaridia              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0x9fe4, .enemy_population_ptr_ = 0xe01c, .enemy_tilesets_ptr = 0x908c, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xda56, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7b9, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xda8c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdb19d), .tileset_ = kTileSet_28_DraygonsRoom              , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0x9ff4, .enemy_population_ptr_ = 0x8000, .enemy_tilesets_ptr = 0x8000, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xdaaa, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7bb, .bg_data_ptr = 0xe113, .room_setup_code = FUNC16(RoomCode_SetPauseCodeForDraygon)          , };
    case 0xda72: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdb19d), .tileset_ = kTileSet_28_DraygonsRoom              , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0x9ff4, .enemy_population_ptr_ = 0xd314, .enemy_tilesets_ptr = 0x8e10, .layer2_scroll_ =  0x101, .rdf_scroll_ptr = 0xdaaa, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7bb, .bg_data_ptr = 0xe108, .room_setup_code = FUNC16(RoomCode_SetPauseCodeForDraygon)          , };
    case 0xdabb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc4fe), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa004, .enemy_population_ptr_ = 0xe42d, .enemy_tilesets_ptr = 0x913e, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr = 0xdadd, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7e1, .bg_data_ptr = 0xe3e8, .room_setup_code = FUNC16(RoomCode_SetCollectedMap)                 , };
    case 0xdb0d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc8dc), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa014, .enemy_population_ptr_ = 0xe516, .enemy_tilesets_ptr = 0x916c, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdb2b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7e9, .bg_data_ptr = 0xe403, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdaf3: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc8dc), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa014, .enemy_population_ptr_ = 0xe1d8, .enemy_tilesets_ptr = 0x90cc, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdb2b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7e9, .bg_data_ptr = 0xe403, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdb5d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdcda0), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa024, .enemy_population_ptr_ = 0xe559, .enemy_tilesets_ptr = 0x917a, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdb7b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7f7, .bg_data_ptr = 0xe3e8, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdb43: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdcda0), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa024, .enemy_population_ptr_ = 0xe440, .enemy_tilesets_ptr = 0x9148, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdb7b, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc7f7, .bg_data_ptr = 0xe3e8, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdba9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd02d), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa034, .enemy_population_ptr_ = 0xe5bf, .enemy_tilesets_ptr = 0x9196, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdbc7, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc805, .bg_data_ptr = 0xe403, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdb8f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd02d), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa034, .enemy_population_ptr_ = 0xe794, .enemy_tilesets_ptr = 0x91f8, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdbc7, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc805, .bg_data_ptr = 0xe403, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdbf9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd3e5), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa044, .enemy_population_ptr_ = 0xe652, .enemy_tilesets_ptr = 0x91a4, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdc17, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc813, .bg_data_ptr = 0xe3e8, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdbdf: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd3e5), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa044, .enemy_population_ptr_ = 0xe4a3, .enemy_tilesets_ptr = 0x915a, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdc17, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc813, .bg_data_ptr = 0xe3e8, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdc45: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd5eb), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa054, .enemy_population_ptr_ = 0xe387, .enemy_tilesets_ptr = 0x9122, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdc63, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc821, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdc2b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd5eb), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Shitroid      , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0xa054, .enemy_population_ptr_ = 0xe387, .enemy_tilesets_ptr = 0x9122, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdc63, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc821, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdc91: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd7c4), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa064, .enemy_population_ptr_ = 0xe25b, .enemy_tilesets_ptr = 0x90de, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdcaf, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc823, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdc77: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd7c4), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Shitroid      , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0xa064, .enemy_population_ptr_ = 0xe25b, .enemy_tilesets_ptr = 0x90de, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdcaf, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc823, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdcdd: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd930), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa074, .enemy_population_ptr_ = 0xe26e, .enemy_tilesets_ptr = 0x90ec, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdcfb, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc831, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdcc3: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdd930), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa074, .enemy_population_ptr_ = 0xe26e, .enemy_tilesets_ptr = 0x90ec, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdcfb, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc831, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdd0c: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcddbf8), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa084, .enemy_population_ptr_ = 0xe708, .enemy_tilesets_ptr = 0x91c4, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdd2c, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc839, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdd3b: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcea823), .tileset_ = kTileSet_24_YellowRefillRoom          , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa094, .enemy_population_ptr_ = 0xe70b, .enemy_tilesets_ptr = 0x91ce, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xdd57, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc841, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdda2: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcddede), .tileset_ = kTileSet_14_MotherBrainsRoom          , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Elevator                              , .room_layer3_fx_ptr_ = 0xa188, .enemy_population_ptr_ = 0x8000, .enemy_tilesets_ptr = 0x8000, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xddc0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc84f, .bg_data_ptr = 0xe48a, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdd88: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcddede), .tileset_ = kTileSet_14_MotherBrainsRoom          , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa0a4, .enemy_population_ptr_ = 0xe321, .enemy_tilesets_ptr = 0x9102, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xddc0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc84f, .bg_data_ptr = 0xe48a, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xdd6e: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcddede), .tileset_ = kTileSet_14_MotherBrainsRoom          , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa0a4, .enemy_population_ptr_ = 0xe321, .enemy_tilesets_ptr = 0x9102, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xddc0, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc84f, .bg_data_ptr = 0xe48a, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xddd1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcde20f), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa0d4, .enemy_population_ptr_ = 0xe384, .enemy_tilesets_ptr = 0x9118, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xddef, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc857, .bg_data_ptr = 0xe41e, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xde00: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcde518), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa0e4, .enemy_population_ptr_ = 0xe857, .enemy_tilesets_ptr = 0x920a, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xde20, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc86b, .bg_data_ptr = 0xe454, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xde30: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce92cb), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa0f4, .enemy_population_ptr_ = 0xe1d5, .enemy_tilesets_ptr = 0x90c2, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xde4c, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc873, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(nullsub_147)                              , };
    case 0xde5a: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcde914), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = kMusic_Song2                                 , .room_layer3_fx_ptr_ = 0xa104, .enemy_population_ptr_ = 0xe3aa, .enemy_tilesets_ptr = 0x9130, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xde78, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_GenRandomExplodes_Every4Frames) , .room_plm_header_ptr = 0xc87b, .bg_data_ptr = 0xe439, .room_setup_code = FUNC16(RoomCode_SetZebesTimebombEvent)           , };
    case 0xde87: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdeb5b), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa114, .enemy_population_ptr_ = 0xe59c, .enemy_tilesets_ptr = 0x9188, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdea5, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ShakeScreenHorizDiag)           , .room_plm_header_ptr = 0xc889, .bg_data_ptr = 0xe454, .room_setup_code = FUNC16(RoomCode_SetLightHorizRoomShake)          , };
    case 0xdeb4: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcded7a), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa124, .enemy_population_ptr_ = 0xe695, .enemy_tilesets_ptr = 0x91b2, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xded2, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_GenRandomExplodes_Every4Frames) , .room_plm_header_ptr = 0xc897, .bg_data_ptr = 0xe46f, .room_setup_code = FUNC16(RoomCode_SetMediumHorizRoomShake)         , };
    case 0xdeeb: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdf534), .tileset_ = kTileSet_13_Tourian                   , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa134, .enemy_population_ptr_ = 0xe102, .enemy_tilesets_ptr = 0x90b0, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr = 0xdf09, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_ShakeScreenHorizDiagStrong)     , .room_plm_header_ptr = 0xc8a5, .bg_data_ptr = 0xe46f, .room_setup_code = FUNC16(RoomCode_Escape4_SetMediumHorizRoomShake) , };
    case 0xdf28: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xce95c2), .tileset_ = kTileSet_25_SaveRoom                  , .music_data_index_ = (uint8)kMusic_Tourian       , .music_track_index_ = kMusic_Song0                                 , .room_layer3_fx_ptr_ = 0xa144, .enemy_population_ptr_ = 0xe791, .enemy_tilesets_ptr = 0x91ee, .layer2_scroll_ =    0x0, .rdf_scroll_ptr = 0xdf44, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xc8b3, .bg_data_ptr =    0x0, .room_setup_code = 0x0                                              , };
    case 0xdf71: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdb846), .tileset_ = kTileSet_18_WhiteCeresElevator        , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa146, .enemy_population_ptr_ = 0xe95c, .enemy_tilesets_ptr = 0x9270, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_CeresElevatorShaft_)            , .room_plm_header_ptr = 0xc8bb, .bg_data_ptr = 0xe1d4, .room_setup_code = FUNC16(RoomCode_SetCeresDoorSolid)               , };
    case 0xdf57: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdb846), .tileset_ = kTileSet_17_BlueCeresElevator         , .music_data_index_ = (uint8)kMusic_Ceres         , .music_track_index_ = kMusic_Song1                                 , .room_layer3_fx_ptr_ = 0xa146, .enemy_population_ptr_ = 0xe88a, .enemy_tilesets_ptr = 0x9218, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_CeresElevatorShaft_)            , .room_plm_header_ptr = 0xc8bb, .bg_data_ptr = 0xe1d4, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xdfb9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdbbfe), .tileset_ = kTileSet_16_WhiteCeres                , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa17e, .enemy_population_ptr_ = 0xea2f, .enemy_tilesets_ptr = 0x927e, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_SpawnCeresFallingDebris)        , .room_plm_header_ptr = 0xc8bd, .bg_data_ptr = 0xe4a5, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xdf9f: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdbbfe), .tileset_ = kTileSet_15_BlueCeres                 , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa156, .enemy_population_ptr_ = 0xe8ad, .enemy_tilesets_ptr = 0x9226, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_SpawnCeresFallingDebris)        , .room_plm_header_ptr = 0xc8bd, .bg_data_ptr = 0xe4a5, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xe003: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdbd78), .tileset_ = kTileSet_16_WhiteCeres                , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa180, .enemy_population_ptr_ = 0xeb02, .enemy_tilesets_ptr = 0x928c, .layer2_scroll_ = 0xc101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(nullsub_148)                             , .room_plm_header_ptr = 0xc8bf, .bg_data_ptr = 0xe4a5, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xdfe9: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdbd78), .tileset_ = kTileSet_15_BlueCeres                 , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa158, .enemy_population_ptr_ = 0xe8d0, .enemy_tilesets_ptr = 0x9234, .layer2_scroll_ = 0x4101, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(nullsub_148)                             , .room_plm_header_ptr = 0xc8bf, .bg_data_ptr = 0xe4a5, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xe04d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdbfc9), .tileset_ = kTileSet_16_WhiteCeres                , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa182, .enemy_population_ptr_ = 0xeb75, .enemy_tilesets_ptr = 0x929a, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(nullsub_148)                             , .room_plm_header_ptr = 0xc8c1, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xe033: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdbfc9), .tileset_ = kTileSet_15_BlueCeres                 , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa15a, .enemy_population_ptr_ = 0xe8f3, .enemy_tilesets_ptr = 0x9242, .layer2_scroll_ =   0xc0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(nullsub_148)                             , .room_plm_header_ptr = 0xc8c1, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xe097: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc330), .tileset_ = kTileSet_16_WhiteCeres                , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa184, .enemy_population_ptr_ = 0xeb98, .enemy_tilesets_ptr = 0x92a8, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(nullsub_148)                             , .room_plm_header_ptr = 0xc8c3, .bg_data_ptr = 0xe4a5, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xe07d: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc330), .tileset_ = kTileSet_15_BlueCeres                 , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa15c, .enemy_population_ptr_ = 0xe916, .enemy_tilesets_ptr = 0x9250, .layer2_scroll_ =  0x1c1, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(nullsub_148)                             , .room_plm_header_ptr = 0xc8c3, .bg_data_ptr = 0xe4a5, .room_setup_code = FUNC16(RoomCode_SpawnHaze)                       , };
    case 0xe0e1: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc43f), .tileset_ = kTileSet_20_WhiteCeresRidleysRoom     , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa186, .enemy_population_ptr_ = 0xebbb, .enemy_tilesets_ptr = 0x92b6, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_HandleCeresRidleyGetaway)       , .room_plm_header_ptr = 0xc8c5, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(RoomCode_SpawnHaze_BgBase)                , };
    case 0xe0c7: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xcdc43f), .tileset_ = kTileSet_19_BlueCeresRidleysRoom      , .music_data_index_ = (uint8)kMusic_BossFight1    , .music_track_index_ = 0x80                                         , .room_layer3_fx_ptr_ = 0xa15e, .enemy_population_ptr_ = 0xe939, .enemy_tilesets_ptr = 0x925e, .layer2_scroll_ =    0x0, .rdf_scroll_ptr =    0x0, .xray_special_casing_ptr =    0x0, .main_code_ptr = FUNC16(RoomCode_HandleCeresRidleyGetaway)       , .room_plm_header_ptr = 0xc8c5, .bg_data_ptr =    0x0, .room_setup_code = FUNC16(RoomCode_SpawnHaze_BgBase)                , };
    case 0xe839: return (RoomDefRoomstate){ .level_data_ptr = LONGPTR(0xceae3e), .tileset_ = kTileSet_11_SandlessMaridia           , .music_data_index_ = (uint8)kMusic_SpcEngine     , .music_track_index_ = kMusic_Stop                                  , .room_layer3_fx_ptr_ = 0xa188, .enemy_population_ptr_ = 0xebce, .enemy_tilesets_ptr = 0x92c3, .layer2_scroll_ = 0xc1c1, .rdf_scroll_ptr =    0x1, .xray_special_casing_ptr =    0x0, .main_code_ptr = 0x0                                             , .room_plm_header_ptr = 0xe87f, .bg_data_ptr = 0xe117, .room_setup_code = 0x0                                              , };
    default: Unreachable(); return (RoomDefRoomstate){ 0 };
  }
}

static uint8 kScroll_9283[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x13          ,   kScroll_Blue  ,   0x80          ,   kScroll_Blue  ,   kScroll_Red   , 
};

static uint8 kScroll_9370[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x8           ,   kScroll_Green ,   0x80          ,   0x8           ,   kScroll_Red   , 
  0x80          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   0x6           ,   kScroll_Green ,   0x80          ,   0x6           ,   kScroll_Red   , 
  0x80          ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          ,   kScroll_Green ,   kScroll_Blue  ,   0x80          ,   0x4           ,   kScroll_Blue  ,   0x80          , 
};

static uint8 kScroll_93d3[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   0x4           ,   kScroll_Red   ,   0x12          ,   0x6           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xfc          ,   0x93          ,   0xe6          ,   0xe5          ,   0xcb          ,   0x92          ,   0xce          ,   0x19          ,   0x9           , 
  0x5           ,   0x10          ,   0x81          ,   0xd8          ,   0x85          ,   0x29          ,   0x81          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xd4          ,   0x81          ,   kScroll_Red   ,   kScroll_Red   ,   0xd3          , 
  0x91          ,   0xbe          ,   0x89          ,   0x5           ,   kScroll_Red   ,   0x26          ,   kScroll_Red   ,   0x8           ,   0x6           ,   0x90          , 
};

static uint8 kScroll_9431[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x6           ,   kScroll_Red   , 
};

static uint8 kScroll_94b9[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  , 
  kScroll_Green ,   0x4           ,   kScroll_Green ,   0x80          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x4           ,   kScroll_Red   ,   0x80          ,   0x8           , 
  kScroll_Red   ,   0x34          ,   0xa           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xf3          ,   0x94          , 
  0xe6          ,   0xe5          ,   0xfc          ,   0x9b          ,   0xc3          ,   kScroll_Green ,   0x9           ,   0x3           ,   0x42          ,   0x81          , 
  0x74          ,   0x8b          ,   0x55          ,   0x82          ,   0xc1          ,   0xc1          ,   0xf9          ,   0x94          ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_94f9[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x9           ,   kScroll_Red   ,   0x31          ,   kScroll_Red   ,   0x7           ,   0x6           , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x24          ,   0x95          ,   0xe6          ,   0xe5          ,   0xb8          ,   0x9d          ,   0xc3          , 
  kScroll_Red   ,   0xc           ,   0x5           ,   0x44          ,   0x81          ,   kScroll_Green ,   0x80          ,   0x9           ,   0x80          ,   0x81          , 
  kScroll_Blue  ,   0x28          ,   0x95          ,   kScroll_Red   ,   kScroll_Red   ,   0x1b          ,   0xc1          ,   0x38          ,   0x82          ,   0xf2          , 
  0xb7          ,   0xce          ,   0x91          ,   0x66          ,   0x8a          ,   0x72          ,   0x8a          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_9528[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   0xa           ,   kScroll_Red   ,   0x38          ,   0x4           ,   kScroll_Blue  ,   0x4           ,   0x70          ,   0xa0          , 
};

static uint8 kScroll_95d3[] = {
  kScroll_Green ,   0xd           ,   kScroll_Red   ,   0x20          ,   0x4           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xfb          ,   0x95          ,   0xe6          ,   0xe5          ,   0xd2          ,   0xbc          ,   0xc3          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x68          ,   0x81          ,   0x3b          ,   0x8b          ,   0x33          ,   0x82          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x46          ,   0x82          ,   kScroll_Red   ,   kScroll_Red   ,   0xd3          ,   0x91          , 
  0xc6          ,   0x8a          ,   0xd2          ,   0x8a          ,   0xe           ,   kScroll_Red   ,   0x24          ,   0x4           ,   kScroll_Green ,   kScroll_Green , 
};

static uint8 kScroll_9657[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x10          ,   kScroll_Red   ,   0xc           ,   kScroll_Green ,   0x6           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x82          ,   0x96          ,   0xe6          ,   0xe5          ,   kScroll_Blue  ,   0xc3          ,   0xc3          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x7c          ,   0x81          ,   0xf2          ,   0x89          ,   0xfd          ,   0x81          ,   0xc1          , 
  0xc1          ,   0x86          ,   0x96          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x5e          ,   0x82          ,   0x99          , 
  0xb8          ,   0xd3          ,   0x91          ,   0xe           ,   0x8b          ,   0x1a          ,   0x8b          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_9686[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   0x4           ,   kScroll_Blue  ,   0x80          ,   0x11          , 
  kScroll_Red   ,   0x2b          ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xb6          ,   0x96          , 
  0xe6          ,   0xe5          ,   0xc           ,   0xc8          ,   0xc3          ,   kScroll_Red   ,   0xc           ,   0x5           ,   0x8c          ,   0x81          , 
  0xb6          ,   0x88          ,   0xc1          ,   0x81          ,   0x81          ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x1b          ,   0xc1          ,   0x6c          ,   0x82          ,   0xa           ,   0xb8          ,   0xce          ,   0x91          ,   0x26          ,   0x8b          , 
};

static uint8 kScroll_9729[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   0x80          , 
  kScroll_Green ,   kScroll_Red   ,   0x80          ,   0x17          ,   kScroll_Blue  ,   0x80          ,   0x17          ,   kScroll_Red   ,   0x80          ,   0x18          , 
  kScroll_Blue  ,   0x80          ,   0x18          ,   kScroll_Red   ,   0x80          ,   0x19          ,   kScroll_Blue  ,   0x80          ,   0x19          ,   kScroll_Red   , 
};

static uint8 kScroll_97a5[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   0x3           ,   kScroll_Green , 
  0x80          ,   kScroll_Red   ,   kScroll_Blue  ,   0x3           ,   kScroll_Red   ,   0x80          ,   0x14          ,   kScroll_Red   ,   0x17          ,   0x11          , 
  kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xfa          ,   0x97          ,   0x52          ,   0xe6          ,   0xe0          , 
  0x97          ,   0xe6          ,   0xe5          ,   0x23          ,   0xdf          ,   0xc3          ,   kScroll_Green ,   0x6           ,   0x5           ,   0xae          , 
  0x81          ,   0x61          ,   0x8b          ,   0x4b          ,   0x82          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x98          ,   kScroll_Red   , 
};

static uint8 kScroll_9800[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x15          ,   kScroll_Red   ,   0x19          ,   0x6           ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x69          ,   0x98          ,   0x12          ,   0xe6          ,   0xe           ,   0x4f          ,   0x98          , 
  0x29          ,   0xe6          ,   0x4           ,   0x35          ,   0x98          ,   0xe6          ,   0xe5          ,   0xd0          ,   0xe0          ,   0xc3          , 
  kScroll_Green ,   0x24          ,   0x3           ,   0xbe          ,   0x81          ,   0xed          ,   0x84          ,   0xb3          ,   0x80          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xfe          ,   0x83          ,   0x5           , 
};

static uint8 kScroll_9965[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x1a          ,   kScroll_Red   ,   0x7           ,   0x8           ,   0x4           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x90          ,   0x99          ,   0xe6          ,   0xe5          ,   0x35          ,   0xeb          ,   0xc3          , 
  kScroll_Green ,   kScroll_Red   ,   0x5           ,   0xc2          ,   0x81          ,   0xca          ,   0x8b          ,   0x71          ,   0x82          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x42          ,   0x84          ,   0xcf          , 
  0xb8          ,   0xd4          ,   0x91          ,   0x16          ,   0x8c          ,   0x22          ,   0x8c          ,   0x1b          ,   kScroll_Red   ,   0x17          , 
};

static uint8 kScroll_99ec[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   0x3           ,   kScroll_Green ,   0x80          , 
  0x3           ,   kScroll_Red   ,   0x80          ,   0x1d          ,   kScroll_Red   ,   0x15          ,   0x9           ,   0x4           ,   0x8           ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x20          ,   0x9a          ,   0xe6          ,   0xe5          ,   0xd3          ,   0xf4          ,   0xc3          ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   0xc4          ,   0x81          ,   0x70          ,   0x88          ,   0xa5          ,   0x81          ,   0xc1          ,   0xc1          , 
  0x24          ,   0x9a          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x78          ,   0x84          ,   0x5           ,   0xb9          , 
};

static uint8 kScroll_9a24[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   0x1e          ,   kScroll_Red   ,   0x11          ,   0x7           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x8a          ,   0x9a          ,   0x12          ,   0xe6          ,   kScroll_Red   ,   0x70          ,   0x9a          ,   0xe6          ,   0xe5          , 
};

static uint8 kScroll_9a8e[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   0x1f          ,   kScroll_Red   ,   0x10          ,   0x7           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xd6          ,   0x9a          ,   0x12          ,   0xe6          ,   kScroll_Red   ,   0xbc          ,   0x9a          ,   0xe6          ,   0xe5          , 
  0x32          ,   0x82          ,   0xc4          ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   0xe4          ,   0x81          ,   0x86          ,   0x85          , 
  0xdd          ,   0x80          ,   0xc1          ,   0xc1          ,   0xd8          ,   0x9a          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x84          ,   0x84          ,   0x5           ,   0xb9          ,   0xd4          ,   0x91          ,   0x32          ,   0x82          ,   0xc4          ,   kScroll_Green , 
};

static uint8 kScroll_9ad8[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   0x9           ,   kScroll_Red   ,   0x4           ,   0xc           ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  kScroll_Red   ,   0x9b          ,   0xe6          ,   0xe5          ,   0xce          ,   0xf1          ,   0xc4          ,   0x6           ,   0xf           ,   0x5           , 
  0x4           ,   0x82          ,   0x7a          ,   0x99          ,   0x41          ,   0x85          ,   kScroll_Red   ,   0xc0          ,   0x16          ,   0x9b          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x8e          ,   0x84          ,   0x37          ,   0xba          ,   0xd5          ,   0x91          , 
  0xa6          ,   0x8c          ,   0xb2          ,   0x8c          ,   0xbe          ,   0x8c          ,   0xca          ,   0x8c          ,   0xd6          ,   0x8c          , 
};

static uint8 kScroll_9b16[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   0x1c          ,   kScroll_Green , 
};

static uint8 kScroll_9b86[] = {
  kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green , 
  0x3           ,   kScroll_Green ,   0x80          ,   kScroll_Green ,   kScroll_Blue  ,   0x6           ,   0x4           ,   0x3           ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0xc4          ,   0x9b          ,   0xe6          ,   0xe5          ,   0x42          ,   0x96          ,   0xc5          ,   0x6           , 
  kScroll_Red   ,   kScroll_Red   ,   0x24          ,   0x82          ,   0x7c          ,   0x8f          ,   0xd5          ,   0x82          ,   0xc1          ,   0xc1          , 
};

static uint8 kScroll_9bf3[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   0x80          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   0x80          , 
  0x4           ,   kScroll_Blue  ,   0xd           ,   0x4           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x2e          , 
  0x9c          ,   0xe6          ,   0xe5          ,   kScroll_Red   ,   0x9b          ,   0xc5          ,   0x6           ,   kScroll_Red   ,   0x3           ,   0x28          , 
  0x82          ,   0x38          ,   0x9f          ,   0xfd          ,   0x85          ,   0xc1          ,   0xc1          ,   0x30          ,   0x9c          ,   kScroll_Red   , 
};

static uint8 kScroll_9c30[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          ,   0x5           ,   kScroll_Blue  ,   0x5           ,   0x4           ,   kScroll_Blue  , 
  kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x5c          ,   0x9c          ,   0xe6          ,   0xe5          ,   0xc3          ,   0x83          , 
  0xce          ,   0x15          ,   kScroll_Red   ,   kScroll_Red   ,   0x2a          ,   0x82          ,   0xbf          ,   0x8f          ,   0xe7          ,   0x82          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x40          ,   0x85          , 
  kScroll_Red   ,   kScroll_Red   ,   0xd5          ,   0x91          ,   0x72          ,   0x8d          ,   0x6           ,   kScroll_Blue  ,   0x6           ,   0x6           , 
};

static uint8 kScroll_9cb2[] = {
  kScroll_Blue  ,   0x8           ,   kScroll_Blue  ,   0xa           ,   0x6           ,   0x7           ,   0x7           ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xda          ,   0x9c          ,   0xe6          ,   0xe5          ,   0x5f          ,   0xa1          ,   0xc5          ,   0x6           ,   kScroll_Red   ,   kScroll_Red   , 
  0x3e          ,   0x82          ,   0x5c          ,   0x9d          ,   0xb9          ,   0x85          ,   0xc0          ,   kScroll_Red   ,   0xe0          ,   0x9c          , 
  kScroll_Red   ,   kScroll_Red   ,   0xe6          ,   0xc1          ,   0x58          ,   0x85          ,   kScroll_Red   ,   kScroll_Red   ,   0xd5          ,   0x91          , 
  0xa2          ,   0x8d          ,   0xae          ,   0x8d          ,   0xba          ,   0x8d          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_9ce0[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   0xb           , 
};

static uint8 kScroll_9d52[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_9e3c[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  , 
  0x3           ,   kScroll_Blue  ,   0x80          ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   0x3           , 
  kScroll_Red   ,   0x80          ,   0xd           ,   kScroll_Blue  ,   0x13          ,   0xa           ,   0x8           ,   0x4           ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x79          ,   0x9e          ,   0xe6          ,   0xe5          ,   0x59          ,   0xd5          ,   0xc5          ,   0x6           ,   0xf           , 
  0x5           ,   0x8e          ,   0x82          ,   0xb9          ,   0x9c          ,   0xa7          ,   0x85          ,   0xc1          ,   0xc1          ,   0x7f          , 
};

static uint8 kScroll_9e7f[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   0xe           ,   kScroll_Blue  ,   0x15          ,   0x8           ,   0x8           ,   0x3           ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xe5          ,   0x9e          ,   0x12          ,   0xe6          ,   kScroll_Red   ,   0xcb          ,   0x9e          ,   0xe6          ,   0xe5          , 
};

static uint8 kScroll_9eed[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x12          ,   kScroll_Blue  ,   0x80          ,   0x12          ,   kScroll_Red   ,   0x80          , 
  0xd           ,   kScroll_Green ,   0x80          ,   0xd           ,   kScroll_Red   ,   0x80          ,   0xf           ,   kScroll_Blue  ,   0x1d          ,   0xa           , 
  kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x57          ,   0x9f          ,   0x12          ,   0xe6          ,   kScroll_Red   , 
};

static uint8 kScroll_9f5d[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          ,   0x10          ,   kScroll_Blue  ,   0x1e          , 
  0x8           ,   0x3           ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xaa          ,   0x9f          ,   0x12          ,   0xe6          , 
  kScroll_Red   ,   0x90          ,   0x9f          ,   0xe6          ,   0xe5          ,   0x6f          ,   0xe8          ,   0xc5          ,   0x6           ,   kScroll_Red   , 
  kScroll_Red   ,   0xb0          ,   0x82          ,   0x6f          ,   0x96          ,   0xb7          ,   0x84          ,   0xc1          ,   0xc1          ,   0xae          , 
  0x9f          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x8c          ,   0x87          ,   0xf4          ,   0xba          ,   0xd5          , 
};

static uint8 kScroll_9fae[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x5           , 
  kScroll_Green ,   0x80          ,   0x11          ,   kScroll_Blue  ,   0x1b          ,   0xd           ,   0x6           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xe1          ,   0x9f          ,   0xe6          ,   0xe5          ,   0xae          ,   0xec          ,   0xc5          ,   0x6           ,   0xf           , 
  0x5           ,   0xc0          ,   0x82          ,   0xa3          ,   0x92          ,   0xa3          ,   0x83          ,   0xc1          ,   0xc1          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xa6          ,   0x87          ,   0x52          ,   0xba          ,   0xd5          , 
};

static uint8 kScroll_a010[] = {
  kScroll_Blue  ,   0x13          ,   kScroll_Blue  ,   0x6           ,   0xa           ,   0x5           ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x38          ,   0xa0          ,   0xe6          ,   0xe5          ,   0x57          ,   0xf0          ,   0xc5          ,   0x6           ,   kScroll_Red   ,   kScroll_Red   , 
  0xd2          ,   0x82          ,   0x78          ,   0x97          ,   0xe5          ,   0x84          ,   0xc1          ,   0xc1          ,   0x40          ,   0xa0          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xb0          ,   0x87          ,   0x52          ,   0xba          ,   0xd5          ,   0x91          , 
  0x2e          ,   0x8f          ,   0x3a          ,   0x8f          ,   0x46          ,   0x8f          ,   0x52          ,   0x8f          ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_a040[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Green ,   0x5           ,   kScroll_Blue  ,   0x6           ,   kScroll_Blue  ,   0x80          ,   0x14          ,   kScroll_Blue  ,   0x5           , 
  0xa           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x78          ,   0xa0          ,   0xe6          ,   0xe5          , 
  0x3e          ,   0xf4          ,   0xc5          ,   0x6           ,   kScroll_Red   ,   kScroll_Red   ,   0xe2          ,   0x82          ,   0x28          ,   0x90          , 
  0x9           ,   0x83          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x7a          ,   0xa0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_a07a[] = {
  kScroll_Blue  ,   0x15          ,   kScroll_Blue  ,   0x9           ,   0xc           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xa2          ,   0xa0          ,   0xe6          ,   0xe5          ,   0xb6          ,   0x89          ,   0xce          ,   0x17          ,   kScroll_Red   ,   kScroll_Red   , 
  0xf2          ,   0x82          ,   0x2b          ,   0x90          ,   0x13          ,   0x83          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xd8          ,   0x87          ,   kScroll_Red   ,   kScroll_Red   ,   0xd5          ,   0x91          , 
  0x6a          ,   0x8f          ,   0x16          ,   kScroll_Blue  ,   0x14          ,   0x9           ,   0x3           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
};

static uint8 kScroll_a0cf[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x17          ,   kScroll_Blue  ,   0x8           ,   0xd           ,   0x7           ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0xf9          ,   0xa0          ,   0xe6          ,   0xe5          ,   0x78          ,   0xf7          ,   0xc5          ,   0x6           , 
  kScroll_Red   ,   kScroll_Red   ,   0x4           ,   0x83          ,   0x1a          ,   0x91          ,   0x61          ,   0x83          ,   0xc1          ,   kScroll_Blue  , 
  0xfd          ,   0xa0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xe8          ,   0x87          ,   0xa3          ,   0xba          , 
  0xd5          ,   0x91          ,   0x8e          ,   0x8f          ,   0x9a          ,   0x8f          ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_a0fd[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          , 
  0x18          ,   kScroll_Blue  ,   0x1c          ,   0xb           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x2e          , 
  0xa1          ,   0xe6          ,   0xe5          ,   0x50          ,   0xfd          ,   0xc5          ,   0x6           ,   kScroll_Red   ,   kScroll_Red   ,   0x14          , 
  0x83          ,   0xb2          ,   0x9e          ,   0xe5          ,   0x85          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   0x88          ,   0xbe          ,   0xba          ,   0xd5          ,   0x91          ,   0xa6          , 
};

static uint8 kScroll_a284[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  0x6           ,   kScroll_Green ,   0x7           ,   kScroll_Green ,   0x80          ,   0x21          ,   kScroll_Blue  ,   0x19          ,   0xf           ,   0x8           , 
  kScroll_Green ,   0x90          ,   0xa0          ,   kScroll_Red   ,   0xba          ,   0xa2          ,   0xe6          ,   0xe5          ,   0xe3          ,   0x91          , 
  0xc6          ,   0x7           ,   kScroll_Red   ,   0x5           ,   0x5e          ,   0x83          ,   0x13          ,   0x9b          ,   0x7f          ,   0x85          , 
  kScroll_Red   ,   kScroll_Red   ,   0xbe          ,   0xa2          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x6e          ,   0x88          , 
};

static uint8 kScroll_a2be[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   0x22          ,   kScroll_Blue  ,   0x17          ,   0xf           , 
  kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xf5          ,   0xa2          ,   0xe6          ,   0xe5          ,   0xf9          , 
  0x9b          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   0x3           ,   0x6e          ,   0x83          ,   0x3b          ,   0x9f          ,   0x7           , 
  0x86          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x76          , 
};

static uint8 kScroll_a357[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   0xf           ,   kScroll_Green ,   0x12          ,   kScroll_Green ,   0x80          ,   0xa           , 
  kScroll_Blue  ,   0x9           ,   kScroll_Green ,   0x80          ,   0xa           ,   kScroll_Red   ,   0x80          ,   0x25          ,   kScroll_Blue  ,   0x23          , 
  0x7           ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xa3          ,   0xa3          ,   0xe6          ,   0xe5          , 
};

static uint8 kScroll_a3a5[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   0x80          ,   0x26          , 
  kScroll_Blue  ,   0x22          ,   0xb           ,   0x3           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xd5          ,   0xa3          , 
  0xe6          ,   0xe5          ,   0x8c          ,   0xb5          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   0x3           ,   0xa0          ,   0x83          , 
  0x61          ,   0x9f          ,   0x1f          ,   0x86          ,   0xc1          ,   0xc1          ,   0xd7          ,   0xa3          ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   0xd8          ,   0x88          ,   0xec          ,   0xbc          ,   0xd6          ,   0x91          ,   0xea          ,   0x90          , 
};

static uint8 kScroll_a3d7[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          ,   0x27          ,   kScroll_Blue  ,   0x22          ,   0x12          , 
  kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x4           ,   0xa4          ,   0xe6          ,   0xe5          ,   0x39          , 
  0xb7          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   kScroll_Red   ,   0xb0          ,   0x83          ,   0x10          ,   0xa1          ,   0x71          , 
  0x86          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x1c          , 
  0x89          ,   0xe7          ,   0xbb          ,   0xd6          ,   0x91          ,   0xf6          ,   0x90          ,   kScroll_Green ,   0x91          ,   0x28          , 
};

static uint8 kScroll_a435[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   0x80          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   0x3           ,   kScroll_Blue  ,   0x80          ,   0x29          ,   kScroll_Blue  , 
  0x26          ,   0x11          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x6e          ,   0xa4          ,   0xe6          , 
  0xe5          ,   0xc7          ,   0xbc          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   0x3           ,   0xd0          ,   0x83          ,   0x1a          , 
  0x96          ,   0x65          ,   0x84          ,   0xc1          ,   0xc1          ,   0x70          ,   0xa4          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_a470[] = {
  kScroll_Blue  ,   0x2a          ,   kScroll_Blue  ,   0x2c          ,   0x12          ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x98          ,   0xa4          ,   0xe6          ,   0xe5          ,   0x83          ,   0xbd          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   0x5           , 
  0xd2          ,   0x83          ,   0x1f          ,   0x94          ,   0xe3          ,   0x83          ,   0xc0          ,   kScroll_Red   ,   0x9e          ,   0xa4          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x76          ,   0x89          ,   kScroll_Red   ,   kScroll_Red   ,   0xd6          ,   0x91          , 
  0x3e          ,   0x91          ,   0x4a          ,   0x91          ,   0x56          ,   0x91          ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  , 
};

static uint8 kScroll_a49e[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   0x3           ,   kScroll_Red   , 
  0x80          ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   0x80          ,   0x3           ,   kScroll_Blue  ,   0x80          ,   0x2b          , 
  kScroll_Blue  ,   0x2b          ,   0x13          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xd8          ,   0xa4          , 
  0xe6          ,   0xe5          ,   0x69          ,   0xc4          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          ,   0x83          , 
  0x8e          ,   0x98          ,   0xd           ,   0x85          ,   0xc0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_a507[] = {
  kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x5           ,   kScroll_Red   ,   0x80          ,   kScroll_Blue  ,   kScroll_Green ,   0x5           ,   kScroll_Blue  ,   0x80          ,   0x5           ,   kScroll_Red   , 
  0x80          ,   0x3           ,   kScroll_Blue  ,   0x5           ,   kScroll_Red   ,   0x80          ,   0x2d          ,   kScroll_Blue  ,   0x2f          ,   0x13          , 
  0x6           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x67          ,   0xa5          ,   0x29          ,   0xe6          ,   kScroll_Blue  , 
  0x4d          ,   0xa5          ,   0xe6          ,   0xe5          ,   0xb9          ,   0xcd          ,   0xc6          ,   0x7           ,   0x27          ,   0x6           , 
};

static uint8 kScroll_a598[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x2f          ,   kScroll_Blue  ,   0x37          , 
  0x12          ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   0x5           ,   0xe5          ,   0xa5          ,   0x29          ,   0xe6          , 
  kScroll_Blue  ,   0xcb          ,   0xa5          ,   0xe6          ,   0xe5          ,   0x20          ,   0xd6          ,   0xc6          ,   0x1a          ,   0x27          , 
  0x6           ,   0xf4          ,   0x83          ,   0xb5          ,   0x9e          ,   0xef          ,   0x85          ,   kScroll_Blue  ,   kScroll_Blue  ,   0xe9          , 
  0xa5          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x2e          ,   0x8a          ,   0x15          ,   0xb8          ,   0xd6          , 
};

static uint8 kScroll_a5e9[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x30          ,   kScroll_Red   ,   0xc           ,   0x8           ,   0x5           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x14          ,   0xa6          ,   0xe6          ,   0xe5          ,   0x8d          ,   0xd8          ,   0xc6          , 
  0x8           ,   kScroll_Red   ,   0x4           ,   0xf6          ,   0x83          ,   0x5e          ,   0x9f          ,   0x15          ,   0x86          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x3c          ,   0x8a          ,   0xa4          , 
  0xbc          ,   0xd6          ,   0x91          ,   0xe6          ,   0x91          ,   0xf2          ,   0x91          ,   0x31          ,   kScroll_Blue  ,   0x20          , 
};

static uint8 kScroll_a697[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          ,   kScroll_Blue  ,   kScroll_Green ,   0x80          , 
  0x34          ,   kScroll_Blue  ,   0x29          ,   0x12          ,   0x3           ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xc8          , 
  0xa6          ,   0xe6          ,   0xe5          ,   0xe0          ,   0xde          ,   0xc6          ,   0x7           ,   0x12          ,   0x3           ,   0x1a          , 
  0x84          ,   0xe4          ,   0x98          ,   0x29          ,   0x85          ,   0xc1          ,   0xc1          ,   0xd0          ,   0xa6          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x5c          ,   0x8a          ,   0x53          ,   0xbc          ,   0xf4          ,   0x91          ,   0x2e          , 
};

static uint8 kScroll_a6d0[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   kScroll_Blue  , 
  kScroll_Green ,   0x80          ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          ,   kScroll_Red   ,   kScroll_Red   ,   0x80          ,   0x35          ,   kScroll_Blue  , 
  0x39          ,   0x13          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Green ,   0x9           ,   0xa7          ,   0xe6          , 
  0xe5          ,   0x55          ,   0xe3          ,   0xc6          ,   0x7           ,   kScroll_Red   ,   0x3           ,   0x2a          ,   0x84          ,   0x66          , 
  0x96          ,   0x99          ,   0x84          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_a844[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x11          ,   kScroll_Green , 
  0x18          ,   kScroll_Blue  ,   0x80          ,   0x5           ,   kScroll_Green ,   0x4           ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x8c          ,   0xa8          ,   0xe6          ,   0xe5          ,   0xed          ,   0x82          ,   0xc7          ,   0x9           , 
};

static uint8 kScroll_a8e6[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   0x3           ,   kScroll_Blue  ,   0x80          ,   0x3           , 
  kScroll_Red   ,   0x80          ,   kScroll_Green ,   kScroll_Green ,   0x80          ,   kScroll_Green ,   kScroll_Red   ,   0x80          ,   0x8           ,   kScroll_Green , 
  kScroll_Green ,   0x4           ,   kScroll_Blue  ,   0x4           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x1f          ,   0xa9          ,   0xe6          , 
  0xe5          ,   0x47          ,   0x8a          ,   0xc7          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0xb0          ,   0x84          ,   0xf6          , 
  0xb1          ,   0x7d          ,   0x89          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_a954[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   0x19          , 
  kScroll_Green ,   0x26          ,   kScroll_Green ,   0x80          ,   0x19          ,   kScroll_Green ,   0x25          ,   kScroll_Green ,   0x26          ,   kScroll_Green , 
};

static uint8 kScroll_a9d7[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x80          ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          ,   0xb           ,   kScroll_Green ,   0x7           ,   0x6           ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xc           ,   0xaa          ,   0xe6          ,   0xe5          ,   0x36          ,   0xa0          ,   0xc7          , 
  0xa           ,   kScroll_Red   ,   0x3           ,   0xe0          ,   0x84          ,   0x3f          ,   0xa6          ,   0xa7          ,   0x87          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xac          ,   0x8b          ,   0x3f          , 
};

static uint8 kScroll_aa39[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0xd           ,   kScroll_Green , 
  0x8           ,   0x5           ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x68          ,   0xaa          ,   0xe6          , 
  0xe5          ,   0x70          ,   0xaa          ,   0xc7          ,   0xa           ,   kScroll_Red   ,   0x5           ,   kScroll_Red   ,   0x85          ,   0xc5          , 
  0xb3          ,   0xcb          ,   0x89          ,   0xc0          ,   kScroll_Red   ,   0x6c          ,   0xaa          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   0xc8          ,   0x8b          ,   kScroll_Red   ,   kScroll_Red   ,   0xf6          ,   0x91          ,   0x1a          ,   0x94          ,   0x26          , 
};

static uint8 kScroll_aa6c[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x80          ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x3           ,   kScroll_Green ,   0x80          ,   0x3           ,   kScroll_Red   ,   0x80          ,   0x3           , 
  kScroll_Green ,   0x80          ,   0xe           ,   kScroll_Green ,   0xa           ,   0xa           ,   kScroll_Green ,   kScroll_Green ,   0x90          ,   0xa0          , 
  kScroll_Green ,   0xa9          ,   0xaa          ,   0xe6          ,   0xe5          ,   0xb3          ,   0xae          ,   0xc7          ,   0x9           ,   0x15          , 
  0x5           ,   0x10          ,   0x85          ,   0xbb          ,   0xa7          ,   0xdf          ,   0x87          ,   kScroll_Red   ,   kScroll_Red   ,   0xb1          , 
};

static uint8 kScroll_aab1[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0xf           ,   kScroll_Green ,   0xc           ,   0xb           ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xdc          ,   0xaa          ,   0xe6          ,   0xe5          ,   0xc2          ,   0x95          ,   0xce          , 
  0x19          ,   0x15          ,   0x5           ,   0x20          ,   0x85          ,   0x42          ,   0xa6          ,   0xb1          ,   0x87          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xfc          ,   0x8b          ,   kScroll_Red   , 
  kScroll_Red   ,   0xf6          ,   0x91          ,   0x62          ,   0x94          ,   0x10          ,   kScroll_Green ,   0x9           ,   0xa           ,   kScroll_Blue  , 
};

static uint8 kScroll_ab36[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x12          ,   kScroll_Green ,   0xb           ,   0xf           ,   0x4           , 
  kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x62          ,   0xab          ,   0xe6          ,   0xe5          ,   0x80          ,   0xb7          , 
  0xc7          ,   0xa           ,   kScroll_Red   ,   kScroll_Red   ,   0x50          ,   0x85          ,   0xd1          ,   0xb4          ,   0x13          ,   0x8a          , 
  0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x14          ,   0x8c          , 
  0xc6          ,   0xbe          ,   0xf6          ,   0x91          ,   0xaa          ,   0x94          ,   0x13          ,   kScroll_Green ,   0x7           ,   0xc           , 
};

static uint8 kScroll_abba[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x15          ,   kScroll_Green ,   0x6           ,   0xc           ,   kScroll_Blue  ,   0x3           , 
  0x90          ,   0xa0          ,   kScroll_Red   ,   0xf9          ,   0xab          ,   0xe6          ,   0xe5          ,   0x91          ,   0xcd          ,   0xc7          , 
  0xa           ,   kScroll_Red   ,   kScroll_Red   ,   0x80          ,   0x85          ,   0x7a          ,   0xb6          ,   0x49          ,   0x8a          ,   0xc1          , 
};

static uint8 kScroll_abfd[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   0x16          ,   kScroll_Green ,   0x4           ,   0xe           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x27          ,   0xac          ,   0xe6          ,   0xe5          ,   0xcd          ,   0xcf          ,   0xc7          ,   0xa           , 
  kScroll_Red   ,   0x5           ,   0x90          ,   0x85          ,   0xbf          ,   0xb3          ,   0xb7          ,   0x89          ,   0xc1          ,   0xc1          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x34          ,   0x8c          ,   0xc6          ,   0xbe          , 
  0xf6          ,   0x91          ,   0xfe          ,   0x94          ,   0xa           ,   0x95          ,   0x17          ,   kScroll_Green ,   0x3           ,   0xe           , 
};

static uint8 kScroll_ac56[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   ,   0x18          ,   kScroll_Green ,   0x12          ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x81          ,   0xac          ,   0xe6          ,   0xe5          ,   0xfe          ,   0xd4          ,   0xc7          , 
  0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0xb0          ,   0x85          ,   0xe7          ,   0xb5          ,   0x37          ,   0x8a          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x3e          ,   0x8c          ,   0x68          , 
  0xbf          ,   0xf6          ,   0x91          ,   0x2e          ,   0x95          ,   0x19          ,   kScroll_Green ,   0x14          ,   kScroll_Green ,   kScroll_Green , 
};

static uint8 kScroll_acae[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          ,   0x1a          ,   kScroll_Green ,   0x16          ,   kScroll_Green ,   kScroll_Green , 
  0x4           ,   0x90          ,   0xa0          ,   kScroll_Red   ,   0xda          ,   0xac          ,   0xe6          ,   0xe5          ,   0x95          ,   0xd8          , 
  0xc7          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0xd0          ,   0x85          ,   0xd8          ,   0xb3          ,   0xd9          ,   0x89          , 
  0xc1          ,   0xc1          ,   0xe8          ,   0xac          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x5a          ,   0x8c          , 
  0x83          ,   0xbf          ,   0xf6          ,   0x91          ,   0x52          ,   0x95          ,   0x5e          ,   0x95          ,   0x6a          ,   0x95          , 
};

static uint8 kScroll_ace8[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x1b          ,   kScroll_Green , 
  0x19          ,   kScroll_Blue  ,   0xc           ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x17          ,   0xad          ,   0xe6          , 
  0xe5          ,   0x8c          ,   0xe0          ,   0xc7          ,   0x9           ,   kScroll_Red   ,   0x5           ,   0xe0          ,   0x85          ,   0x8f          , 
  0xb8          ,   0xbb          ,   0x8a          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   0x6e          ,   0x8c          ,   0x5a          ,   0xbe          ,   0xf6          ,   0x91          ,   0xa6          ,   0x95          ,   0xb2          , 
};

static uint8 kScroll_ad8f[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   0x80          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          , 
  0x1e          ,   kScroll_Green ,   0x19          ,   0x4           ,   0x4           ,   kScroll_Green ,   0x90          ,   0xa0          ,   kScroll_Red   ,   0xd4          , 
  0xad          ,   0xe6          ,   0xe5          ,   kScroll_Green ,   0xff          ,   0xc7          ,   0x9           ,   kScroll_Red   ,   0x5           ,   0x20          , 
};

static uint8 kScroll_adda[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x1f          ,   kScroll_Green ,   0x1d          ,   0x4           ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x5           ,   0xae          ,   0xe6          ,   0xe5          ,   0x32          ,   0x85          ,   0xc8          , 
  0x9           ,   kScroll_Red   ,   0x3           ,   0x30          ,   0x86          ,   0xee          ,   0xa4          ,   0x1d          ,   0x87          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xca          ,   0x8c          ,   0xc6          , 
  0xbe          ,   0xf6          ,   0x91          ,   0x2a          ,   0x96          ,   0x20          ,   kScroll_Green ,   0x19          ,   0x6           ,   0x4           , 
};

static uint8 kScroll_ae5d[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   0x6           , 
  kScroll_Blue  ,   0x7           ,   kScroll_Blue  ,   0x80          ,   0x8           ,   kScroll_Blue  ,   0x80          ,   0x8           ,   kScroll_Red   ,   0x80          , 
  0x7           ,   kScroll_Red   ,   0x80          ,   0x22          ,   kScroll_Green ,   0x19          ,   0x8           ,   kScroll_Green ,   0x3           ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x9b          ,   0xae          ,   0xe6          ,   0xe5          ,   0x3a          ,   0x94          ,   0xc8          ,   0x9           , 
  kScroll_Red   ,   kScroll_Red   ,   0x70          ,   0x86          ,   0x95          ,   0xb9          ,   0xdf          ,   0x8a          ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_aea3[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Blue  ,   0x80          ,   kScroll_Green , 
  kScroll_Red   ,   0x3           ,   kScroll_Green ,   0x80          ,   0x3           ,   kScroll_Red   ,   0x80          ,   0x23          ,   kScroll_Green ,   0x17          , 
  0x8           ,   0x3           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xdb          ,   0xae          ,   0xe6          ,   0xe5          , 
  0x5d          ,   0x9d          ,   0xc8          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0x80          ,   0x86          ,   0x53          ,   0xac          , 
  0x87          ,   0x88          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_af0c[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   0x80          ,   0x25          ,   kScroll_Green , 
  0x16          ,   0xa           ,   0x4           ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x3b          ,   0xaf          ,   0xe6          , 
  0xe5          ,   0xcf          ,   0xa2          ,   0xc8          ,   0x9           ,   kScroll_Red   ,   0x5           ,   0xa0          ,   0x86          ,   0x9           , 
  0xad          ,   0xa3          ,   0x88          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   0x7e          ,   0x8d          ,   0x5a          ,   0xbe          ,   0xf6          ,   0x91          ,   0xd2          ,   0x96          ,   0xde          , 
};

static uint8 kScroll_af6e[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x27          ,   kScroll_Green ,   0x14          ,   0x5           ,   kScroll_Green ,   kScroll_Green , 
  0xa0          ,   0xa0          ,   kScroll_Red   ,   0x99          ,   0xaf          ,   0xe6          ,   0xe5          ,   0xed          ,   0xab          ,   0xc8          , 
  0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0xc0          ,   0x86          ,   0xd7          ,   0xbb          ,   0x3b          ,   0x8b          ,   0xc0          , 
  kScroll_Red   ,   0x9f          ,   0xaf          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x88          ,   0x8d          ,   kScroll_Red   , 
  kScroll_Red   ,   0xf6          ,   0x91          ,   0xe           ,   0x97          ,   0x1a          ,   0x97          ,   0x26          ,   0x97          ,   kScroll_Green , 
};

static uint8 kScroll_af9f[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x28          ,   kScroll_Green ,   0x11          ,   0x4           ,   0x5           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xca          ,   0xaf          ,   0xe6          ,   0xe5          ,   0x5b          ,   0xb1          ,   0xc8          , 
  0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0xd0          ,   0x86          ,   0xa8          ,   0xa6          ,   0xc9          ,   0x87          ,   0xc1          , 
  0xc1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x96          ,   0x8d          ,   0xc6          , 
  0xbe          ,   0xf6          ,   0x91          ,   0x32          ,   0x97          ,   0x3e          ,   0x97          ,   0x29          ,   kScroll_Green ,   0x10          , 
};

static uint8 kScroll_b0a5[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   0x80          ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  , 
  kScroll_Blue  ,   0x80          ,   kScroll_Red   ,   kScroll_Red   ,   0x80          ,   0x2e          ,   kScroll_Green ,   0x9           ,   0x4           ,   kScroll_Blue  , 
  kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xdb          ,   0xb0          ,   0xe6          ,   0xe5          ,   0xc3          ,   0x83          , 
  0xce          ,   0x15          ,   kScroll_Red   ,   kScroll_Red   ,   0x40          ,   0x87          ,   0x5d          ,   0xa5          ,   0x5b          ,   0x87          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xd8          ,   0x8d          , 
};

static uint8 kScroll_b131[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x31          ,   kScroll_Green , 
  0x13          ,   0x6           ,   kScroll_Blue  ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x60          ,   0xb1          ,   0xe6          , 
  0xe5          ,   0x65          ,   0xc1          ,   0xc8          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0x62          ,   0x87          ,   0x67          , 
  0xa9          ,   0x33          ,   0x88          ,   kScroll_Blue  ,   0xc1          ,   0x64          ,   0xb1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   0xea          ,   0x8d          ,   0xe1          ,   0xbe          ,   0xf6          ,   0x91          ,   0xf2          ,   0x97          ,   0xfe          , 
};

static uint8 kScroll_b164[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x32          ,   kScroll_Green ,   0xb           ,   0x5           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x8e          ,   0xb1          ,   0xe6          ,   0xe5          ,   0xf6          ,   0x9e          ,   0xce          ,   0x19          , 
  0x15          ,   0x5           ,   0x64          ,   0x87          ,   0xf0          ,   0xb1          ,   0x69          ,   0x89          ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xec          ,   0x8d          ,   kScroll_Red   ,   kScroll_Red   , 
  0xf6          ,   0x91          ,   0xa           ,   0x98          ,   0x16          ,   0x98          ,   0x33          ,   kScroll_Green ,   0x10          ,   0x8           , 
};

static uint8 kScroll_b1e4[] = {
  kScroll_Blue  ,   0x35          ,   kScroll_Green ,   0xf           ,   0xd           ,   0x3           ,   0x3           ,   0x90          ,   0xa0          ,   kScroll_Red   , 
  0xc           ,   0xb2          ,   0xe6          ,   0xe5          ,   0xd3          ,   0xc4          ,   0xc8          ,   0x9           ,   0x18          ,   0x5           , 
  0x6a          ,   0x87          ,   0x3c          ,   0xa2          ,   0xb1          ,   0x86          ,   0xc1          ,   0xc1          ,   0x10          ,   0xb2          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x4           ,   0x8e          ,   0x32          ,   0xbf          ,   0xf7          ,   0x91          , 
  0x3a          ,   0x98          ,   0x46          ,   0x98          ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   , 
};

static uint8 kScroll_b210[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x3           , 
  kScroll_Blue  ,   0x4           ,   kScroll_Blue  ,   0x6           ,   kScroll_Red   ,   0x7           ,   kScroll_Red   ,   0x8           ,   kScroll_Red   ,   0x80          , 
  0x3           ,   kScroll_Green ,   0x4           ,   kScroll_Green ,   0x6           ,   kScroll_Green ,   0x7           ,   kScroll_Green ,   0x80          ,   0x4           , 
  kScroll_Red   ,   0x6           ,   kScroll_Blue  ,   0x7           ,   kScroll_Blue  ,   0x8           ,   kScroll_Blue  ,   0x80          ,   0x36          ,   kScroll_Green , 
  0x11          ,   0xb           ,   0x8           ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x5d          ,   0xb2          ,   0xe6          , 
};

static uint8 kScroll_b265[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0xc           ,   kScroll_Green ,   0x80          ,   0xc           ,   kScroll_Red   ,   0x80          , 
  0x37          ,   kScroll_Green ,   0x12          ,   0xf           ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xc9          , 
  0xb2          ,   0x29          ,   0xe6          ,   0x4           ,   0xaf          ,   0xb2          ,   0xe6          ,   0xe5          ,   0x9d          ,   0xe0          , 
};

static uint8 kScroll_b2cd[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  , 
  0x3           ,   kScroll_Blue  ,   0x80          ,   0x38          ,   kScroll_Green ,   0x15          ,   0xe           ,   0x4           ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   kScroll_Blue  ,   0xb3          ,   0xe6          ,   0xe5          ,   kScroll_Red   ,   0xe9          ,   0xc8          ,   0x9           , 
  0x18          ,   0x5           ,   0xaa          ,   0x87          ,   0x8b          ,   0xa4          ,   0xf           ,   0x87          ,   0xc1          ,   0xc1          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x82          ,   0x8e          ,   0x17          ,   0xbf          , 
};

static uint8 kScroll_b378[] = {
  kScroll_Green ,   kScroll_Green ,   0x3b          ,   kScroll_Green ,   0x18          ,   0x10          ,   0x3           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xa1          ,   0xb3          ,   0xe6          ,   0xe5          ,   0xce          ,   0xed          ,   0xc8          ,   0x9           ,   0x18          , 
  0x5           ,   0xcc          ,   0x87          ,   0x69          ,   0xb7          ,   0x97          ,   0x8a          ,   0xc1          ,   0xc1          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xa6          ,   0x8e          ,   0x4d          ,   0xbf          ,   0xf7          , 
  0x91          ,   0xca          ,   0x98          ,   0xd6          ,   0x98          ,   0x3c          ,   kScroll_Green ,   0x19          ,   0xc           ,   kScroll_Blue  , 
};

static uint8 kScroll_b3d6[] = {
  kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Green ,   0x80          ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  , 
  0x80          ,   0x3d          ,   kScroll_Green ,   0x1a          ,   0xb           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x8           ,   0xb4          ,   0xe6          ,   0xe5          ,   0xb           ,   0xf4          ,   0xc8          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   , 
  0xec          ,   0x87          ,   0x6           ,   0xad          ,   0x99          ,   0x88          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xd4          ,   0x8e          ,   0x90          ,   0xbe          ,   0xf7          ,   0x91          , 
};

static uint8 kScroll_b435[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x6           ,   kScroll_Blue  ,   0x80          ,   0x6           , 
  kScroll_Red   ,   0x80          ,   0x7           ,   kScroll_Blue  ,   0x80          ,   0x7           ,   kScroll_Red   ,   0x80          ,   0xe           ,   kScroll_Blue  , 
  0x80          ,   0xe           ,   kScroll_Red   ,   0x80          ,   0x3f          ,   kScroll_Green ,   0x1a          ,   0xe           ,   0x4           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x7e          ,   0xb4          ,   0xe6          ,   0xe5          ,   0xc5          ,   0xfc          ,   0xc8          , 
};

static uint8 kScroll_b4da[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green , 
  0x80          ,   0x42          ,   kScroll_Green ,   0x1f          ,   0x9           ,   0x4           ,   0x5           ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xc           ,   0xb5          ,   0xe6          ,   0xe5          ,   0x9f          ,   0x89          ,   0xc9          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   , 
  0x3c          ,   0x88          ,   0xf4          ,   0xae          ,   0x1d          ,   0x89          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x7a          ,   0x8f          ,   0x5a          ,   0xbe          ,   0xf7          ,   0x91          , 
};

static uint8 kScroll_b53d[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Blue  ,   0x6           ,   kScroll_Red   ,   0x80          ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   0x6           ,   kScroll_Blue  ,   0x80          ,   0x3           ,   kScroll_Blue  ,   0x4           ,   kScroll_Green ,   0x80          ,   0x44          , 
  kScroll_Green ,   0x25          ,   0x6           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x81          ,   0xb5          , 
  0xe6          ,   0xe5          ,   0xe2          ,   0x9c          ,   0xc9          ,   0x9           ,   kScroll_Red   ,   kScroll_Red   ,   0x6c          ,   0x88          , 
};

static uint8 kScroll_b5b4[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   0xa           ,   kScroll_Green ,   0xd           ,   kScroll_Green ,   0x80          , 
  0xa           ,   kScroll_Red   ,   0xd           ,   kScroll_Red   ,   0x80          ,   kScroll_Red   ,   kScroll_Green ,   0x3           ,   kScroll_Green ,   0x80          , 
  kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x46          ,   kScroll_Green ,   0x20          ,   0xe           ,   0x6           ,   0x3           ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0xfc          ,   0xb5          ,   0xe6          ,   0xe5          ,   0x8c          ,   0xa8          ,   0xc9          ,   0x9           , 
};

static uint8 kScroll_b600[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x7           ,   kScroll_Green , 
  0x80          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x7           ,   kScroll_Red   ,   0x80          ,   0x4           ,   kScroll_Blue  ,   0x80          ,   kScroll_Red   , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          ,   0x4           ,   kScroll_Red   ,   0x80          ,   kScroll_Red   ,   kScroll_Red   ,   0x80          , 
  kScroll_Blue  ,   kScroll_Red   ,   0x80          ,   0x47          ,   kScroll_Green ,   0x1e          ,   0x10          ,   0x3           ,   kScroll_Blue  ,   0x70          , 
};

static uint8 kScroll_b681[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   0x9           ,   kScroll_Red   ,   0x80          ,   0x8           ,   kScroll_Blue  ,   0x9           ,   kScroll_Blue  ,   0x80          , 
  0x8           ,   kScroll_Red   ,   0x80          ,   0x49          ,   kScroll_Green ,   0x16          ,   0x11          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0xbf          ,   0xb6          ,   0xe6          ,   0xe5          ,   0xd           ,   0xc3          ,   0xc9          ,   0x9           , 
  kScroll_Red   ,   kScroll_Red   ,   0xbc          ,   0x88          ,   0xab          ,   0xae          ,   0xf3          ,   0x88          ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_b71b[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   0xb           ,   kScroll_Blue  , 
  0x80          ,   0xb           ,   kScroll_Green ,   0xd           ,   kScroll_Green ,   0xe           ,   kScroll_Green ,   0x80          ,   kScroll_Red   ,   kScroll_Blue  , 
  0x4           ,   kScroll_Red   ,   0x80          ,   kScroll_Blue  ,   kScroll_Green ,   0x4           ,   kScroll_Green ,   0x80          ,   0x4c          ,   kScroll_Green , 
  0x24          ,   0xc           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x68          ,   0xb7          ,   0xe6          , 
};

static uint8 kScroll_c9da[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   0xe           ,   kScroll_Blue  , 
  0xf           ,   kScroll_Blue  ,   0x80          ,   0x4           ,   kScroll_Red   ,   0x5           ,   kScroll_Green ,   0xb           ,   kScroll_Green ,   0x10          , 
  kScroll_Blue  ,   0x11          ,   kScroll_Blue  ,   0x80          ,   0x5           ,   kScroll_Blue  ,   0x80          ,   0x4           ,   kScroll_Blue  ,   0x80          , 
  0x5           ,   kScroll_Red   ,   0x80          ,   0x4           ,   kScroll_Red   ,   0x80          ,   kScroll_Blue  ,   0x3           ,   0xc           ,   0xe           , 
};

static uint8 kScroll_ca9e[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   0x80          , 
  0x3           ,   kScroll_Blue  ,   0x80          ,   0x3           ,   kScroll_Green ,   0x80          ,   0x3           ,   0x3           ,   0x13          ,   0xa           , 
  0x3           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xf4          ,   0xca          ,   0x29          ,   0xe6          ,   kScroll_Blue  , 
  0xda          ,   0xca          ,   0xe6          ,   0xe5          ,   0x20          ,   0xa7          ,   0xc4          ,   0x5           ,   kScroll_Red   ,   kScroll_Red   , 
  0xd4          ,   0x9b          ,   0xe1          ,   0xc1          ,   0x13          ,   0x8c          ,   0xc1          ,   0xc1          ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_cb4a[] = {
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x21          ,   kScroll_Blue  , 
};

static uint8 kScroll_cc21[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   0x7           ,   0x3           ,   0x12          ,   0xd           , 
  0x3           ,   kScroll_Green ,   0x90          ,   0xa0          ,   kScroll_Red   ,   0x6d          ,   0xcc          ,   0x29          ,   0xe6          ,   kScroll_Blue  , 
  0x53          ,   0xcc          ,   0xe6          ,   0xe5          ,   0x83          ,   0xd8          ,   0xc4          ,   0x5           ,   kScroll_Red   ,   0x3           , 
  0x14          ,   0x9c          ,   0xe7          ,   0xc1          ,   0x27          ,   0x8c          ,   0xc0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x8f          ,   0xc2          ,   kScroll_Red   ,   kScroll_Red   ,   0xc7          ,   0xc8          , 
};

static uint8 kScroll_ccbb[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   0x3           ,   kScroll_Blue  ,   0x4           ,   kScroll_Blue  ,   0x80          , 
  0x3           ,   kScroll_Red   ,   0x80          ,   0x4           ,   kScroll_Red   ,   0x80          ,   0x9           ,   0x3           ,   0xd           ,   0x13          , 
  kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x11          ,   0xcd          ,   0x29          ,   0xe6          ,   kScroll_Blue  , 
  0xf7          ,   0xcc          ,   0xe6          ,   0xe5          ,   0xc3          ,   0x83          ,   0xce          ,   0x16          ,   kScroll_Red   ,   kScroll_Red   , 
  0x34          ,   0x9c          ,   0xed          ,   0xc1          ,   0x3b          ,   0x8c          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_cd5b[] = {
  kScroll_Blue  ,   0xb           ,   0x3           ,   0x11          ,   0xf           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xa2          ,   0xcd          ,   0x29          ,   0xe6          ,   kScroll_Blue  ,   0x88          ,   0xcd          ,   0xe6          ,   0xe5          ,   0xa5          , 
  0xe6          ,   0xc4          ,   0x5           ,   kScroll_Red   ,   kScroll_Red   ,   0x54          ,   0x9c          ,   0xa5          ,   0xc1          ,   0xe3          , 
  0x8b          ,   0xc1          ,   0xc1          ,   0xa6          ,   0xcd          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xbb          , 
  0xc2          ,   0x83          ,   0xe1          ,   0xd0          ,   0xc8          ,   0xa5          ,   0xe6          ,   0xc4          ,   0x4           ,   kScroll_Red   , 
};

static uint8 kScroll_cda6[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   0xc           ,   0x3           ,   0xf           ,   0x11          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xee          ,   0xcd          ,   0x29          ,   0xe6          ,   kScroll_Blue  ,   0xd4          ,   0xcd          ,   0xe6          ,   0xe5          , 
  0x4e          ,   0xe9          ,   0xc4          ,   0x5           ,   kScroll_Red   ,   kScroll_Red   ,   0x64          ,   0x9c          ,   0x9f          ,   0xc1          , 
  0xcf          ,   0x8b          ,   0xc1          ,   0xc1          ,   0xf0          ,   0xcd          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0xbd          ,   0xc2          ,   0x83          ,   0xe1          ,   0xd0          ,   0xc8          ,   0x4e          ,   0xe9          ,   0xc4          ,   0x4           , 
};

static uint8 kScroll_cdf0[] = {
  kScroll_Blue  ,   0xd           ,   0x3           ,   0x12          ,   0x11          ,   0x4           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x37          ,   0xce          ,   0x29          ,   0xe6          ,   kScroll_Blue  ,   0x1d          ,   0xce          ,   0xe6          ,   0xe5          ,   0x8f          , 
  0xea          ,   0xc4          ,   0x5           ,   kScroll_Red   ,   kScroll_Red   ,   0x74          ,   0x9c          ,   0xc5          ,   0xc8          ,   0xbf          , 
  0x8c          ,   0xc1          ,   0xc1          ,   0x39          ,   0xce          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xbf          , 
  0xc2          ,   0x9e          ,   0xe1          ,   0xd0          ,   0xc8          ,   0x98          ,   0xed          ,   0xc4          ,   0x4           ,   kScroll_Red   , 
};

static uint8 kScroll_ce39[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   0x3           ,   kScroll_Blue  ,   0x80          ,   0xe           ,   0x3           ,   0xa           , 
  0xd           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x86          ,   0xce          ,   0x29          ,   0xe6          , 
  kScroll_Blue  ,   0x6c          ,   0xce          ,   0xe6          ,   0xe5          ,   0xa1          ,   0xf0          ,   0xc4          ,   0x5           ,   kScroll_Red   , 
  kScroll_Red   ,   0x74          ,   0x9c          ,   0xea          ,   0xc1          ,   0x31          ,   0x8c          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xc7          ,   0xc2          ,   0x83          ,   0xe1          ,   0xd0          , 
};

static uint8 kScroll_cf49[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   0x80          ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  0x80          ,   kScroll_Green ,   0x4           ,   0xa           ,   0x12          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x7b          ,   0xcf          ,   0xe6          ,   0xe5          ,   0xae          ,   0xe6          ,   0xc9          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   , 
  0xa4          ,   0x9c          ,   0x3c          ,   0xd5          ,   0x8c          ,   0x8e          ,   kScroll_Red   ,   kScroll_Red   ,   0x7f          ,   0xcf          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xdf          ,   0xc3          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          , 
};

static uint8 kScroll_cf7f[] = {
  kScroll_Blue  ,   0x3           ,   0x4           ,   0xc           ,   0x11          ,   0x4           ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xa7          ,   0xcf          ,   0xe6          ,   0xe5          ,   0x9           ,   0xe8          ,   0xc9          ,   0xb           ,   0x12          ,   0x5           , 
  0xb4          ,   0x9c          ,   0x3f          ,   0xd5          ,   0x96          ,   0x8e          ,   kScroll_Red   ,   kScroll_Red   ,   0xad          ,   0xcf          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xe1          ,   0xc3          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          , 
  0x78          ,   0xa3          ,   0x84          ,   0xa3          ,   0x90          ,   0xa3          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_cfad[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Red   ,   0x4           ,   kScroll_Red   ,   0x80          ,   kScroll_Red   ,   kScroll_Green ,   0x4           ,   kScroll_Blue  ,   0x80          , 
  kScroll_Red   ,   kScroll_Red   ,   0x4           ,   kScroll_Blue  ,   0x80          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          ,   0x4           ,   0x4           , 
  0xa           ,   0x9           ,   0x3           ,   0x8           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xf0          ,   0xcf          ,   0xe6          , 
  0xe5          ,   0x25          ,   0xf2          ,   0xc9          ,   0xb           ,   0x1b          ,   0x6           ,   0xc4          ,   0x9c          ,   0x6d          , 
};

static uint8 kScroll_cffa[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   0x7           ,   kScroll_Blue  ,   0xa           ,   kScroll_Red   ,   0x80          ,   0x5           , 
  0x4           ,   0xd           ,   0xd           ,   0x4           ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x3e          ,   0xd0          , 
  0xe6          ,   0xe5          ,   0xff          ,   0x8e          ,   0xca          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   ,   0xd4          ,   0x9c          , 
};

static uint8 kScroll_d046[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Green ,   0xa           ,   kScroll_Green ,   0x80          ,   0x6           ,   0x4           ,   0x11          ,   0xc           ,   0x3           , 
  0x4           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x7c          ,   0xd0          ,   0xe6          ,   0xe5          ,   0x13          ,   0xa1          , 
  0xca          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   ,   0xe4          ,   0x9c          ,   0xe2          ,   0xd5          ,   0xa8          ,   0x8e          , 
  kScroll_Red   ,   0xc0          ,   0x7e          ,   0xd0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x7d          ,   0xc4          , 
};

static uint8 kScroll_d07e[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   0x7           ,   0x4           ,   0xc           ,   0x10          ,   0x4           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xb1          ,   0xd0          ,   0xe6          ,   0xe5          ,   0x99          ,   0xaf          ,   0xca          ,   0xb           ,   0x1b          , 
  0x6           ,   0xf4          ,   0x9c          ,   0x35          ,   0xd6          ,   0xb6          ,   0x8e          ,   0xc1          ,   0xc1          ,   0xb5          , 
  0xd0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x8b          ,   0xc4          ,   0x48          ,   0xe2          ,   0xd1          , 
};

static uint8 kScroll_d0b5[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x8           ,   0x4           ,   0xc           ,   0x9           ,   0x6           ,   0x4           , 
  0x90          ,   0xa0          ,   kScroll_Red   ,   0xe0          ,   0xd0          ,   0xe6          ,   0xe5          ,   0x4f          ,   0xb2          ,   0xca          , 
  0xb           ,   kScroll_Red   ,   kScroll_Red   ,   0x4           ,   0x9d          ,   0x6a          ,   0xce          ,   0x41          ,   0x8d          ,   0xc0          , 
  0xc0          ,   0xec          ,   0xd0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x99          ,   0xc4          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd1          ,   0xc8          ,   0x2c          ,   0xa4          ,   0x38          ,   0xa4          ,   0x44          ,   0xa4          ,   0x50          , 
};

static uint8 kScroll_d0ec[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   0x9           ,   0x4           ,   0xc           ,   0x7           ,   0x3           ,   kScroll_Green , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x2b          ,   0xd1          ,   0xe6          ,   0xe5          ,   0x42          ,   0xce          ,   0xca          , 
  0xb           ,   0x1b          ,   0x6           ,   0x14          ,   0x9d          ,   0xaa          ,   0xd3          ,   0x2c          ,   0x8e          ,   kScroll_Red   , 
};

static uint8 kScroll_d12f[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x80          ,   kScroll_Blue  , 
  kScroll_Blue  ,   0x80          ,   0xa           ,   0x4           ,   0xc           ,   0x4           ,   kScroll_Green ,   0x3           ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x62          ,   0xd1          ,   0xe6          ,   0xe5          ,   0x74          ,   0xd4          ,   0xca          ,   0xb           ,   kScroll_Red   , 
  kScroll_Red   ,   0x24          ,   0x9d          ,   0x90          ,   0xcf          ,   0x65          ,   0x8d          ,   0xc0          ,   kScroll_Red   ,   0x64          , 
  0xd1          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xa9          ,   0xc4          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          , 
};

static uint8 kScroll_d164[] = {
  kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x4           ,   kScroll_Blue  ,   0x80          ,   0xb           , 
  0x4           ,   0xe           ,   0x4           ,   0x4           ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x94          ,   0xd1          , 
  0xe6          ,   0xe5          ,   0xc8          ,   0xdb          ,   0xca          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   ,   0x34          ,   0x9d          , 
  0x98          ,   0xd6          ,   0xc4          ,   0x8e          ,   0xc0          ,   kScroll_Red   ,   0x98          ,   0xd1          ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   0xbd          ,   0xc4          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          ,   0x98          ,   0xa4          , 
};

static uint8 kScroll_d198[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   0x5           ,   kScroll_Blue  , 
  0x80          ,   0xc           ,   0x4           ,   0x12          ,   0x7           ,   kScroll_Green ,   0x4           ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xca          ,   0xd1          ,   0xe6          ,   0xe5          ,   0x58          ,   0xe4          ,   0xca          ,   0xb           ,   0x1b          ,   0x6           , 
  0x44          ,   0x9d          ,   0xc3          ,   0xcf          ,   0x77          ,   0x8d          ,   kScroll_Red   ,   0xc0          ,   0xd0          ,   0xd1          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xef          ,   0xc4          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          , 
};

static uint8 kScroll_d1d0[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   0x4           ,   kScroll_Green , 
  0x6           ,   kScroll_Blue  ,   0x80          ,   0xd           ,   0x4           ,   0x12          ,   0x4           ,   0x4           ,   0x3           ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x4           ,   0xd2          ,   0xe6          ,   0xe5          ,   0x9c          ,   0xf5          ,   0xca          ,   0xb           , 
  kScroll_Red   ,   kScroll_Red   ,   0x54          ,   0x9d          ,   0x5b          ,   0xd7          ,   0xd6          ,   0x8e          ,   0xc0          ,   kScroll_Red   , 
  0xa           ,   0xd2          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x3           ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_d20a[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Red   ,   0xa           ,   kScroll_Green ,   0x80          ,   0xa           ,   kScroll_Red   ,   0x80          ,   0xe           ,   0x4           , 
  0x10          ,   0x10          ,   kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x43          ,   0xd2          ,   0xe6          , 
  0xe5          ,   0xdb          ,   0x83          ,   0xcb          ,   0xb           ,   0x1b          ,   0x5           ,   0x64          ,   0x9d          ,   0x17          , 
  0xde          ,   0x1a          ,   0x90          ,   kScroll_Red   ,   kScroll_Red   ,   0x4b          ,   0xd2          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_d24b[] = {
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x80          ,   0xf           ,   0x4           ,   0x11          , 
  0x10          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x79          ,   0xd2          ,   0xe6          ,   0xe5          , 
  0x3a          ,   0x88          ,   0xcb          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   ,   0x74          ,   0x9d          ,   0xee          ,   0xd7          , 
  0xec          ,   0x8e          ,   0xc0          ,   kScroll_Red   ,   0x7d          ,   0xd2          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x4f          ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          ,   0x28          ,   0xa5          ,   0x34          ,   0xa5          , 
};

static uint8 kScroll_d27d[] = {
  kScroll_Blue  ,   0x10          ,   0x4           ,   0x1a          ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xa5          ,   0xd2          ,   0xe6          ,   0xe5          ,   0xe0          ,   0x89          ,   0xcb          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   , 
  0x84          ,   0x9d          ,   kScroll_Blue  ,   0xd8          ,   0xfa          ,   0x8e          ,   kScroll_Red   ,   kScroll_Red   ,   0xa9          ,   0xd2          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x51          ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          , 
  0x40          ,   0xa5          ,   0x4c          ,   0xa5          ,   kScroll_Blue  ,   0x11          ,   0x4           ,   0x1b          ,   kScroll_Red   ,   kScroll_Green , 
};

static uint8 kScroll_d2a9[] = {
  kScroll_Blue  ,   0x11          ,   0x4           ,   0x1b          ,   kScroll_Red   ,   kScroll_Green ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xd1          ,   0xd2          ,   0xe6          ,   0xe5          ,   0xd4          ,   0x8b          ,   0xcb          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   , 
  0x94          ,   0x9d          ,   0xed          ,   0xd3          ,   0x42          ,   0x8e          ,   0xc0          ,   kScroll_Red   ,   0xd3          ,   0xd2          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x53          ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          , 
  0x58          ,   0xa5          ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x12          ,   0x4           , 
};

static uint8 kScroll_d2d3[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x12          ,   0x4           ,   0x1b          ,   0x5           , 
  0x7           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   kScroll_Red   ,   0xd3          ,   0xe6          ,   0xe5          ,   0x92          , 
  0x97          ,   0xcb          ,   0xb           ,   kScroll_Red   ,   kScroll_Red   ,   0xa4          ,   0x9d          ,   0x64          ,   0xd8          ,   0xc           , 
  0x8f          ,   0xc0          ,   kScroll_Red   ,   0x4           ,   0xd3          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x61          , 
  0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          ,   0x64          ,   0xa5          ,   0x70          ,   0xa5          ,   kScroll_Blue  , 
};

static uint8 kScroll_d304[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x13          ,   0x4           ,   0x22          , 
  kScroll_Red   ,   kScroll_Blue  ,   0x6           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x32          ,   0xd3          ,   0xe6          ,   0xe5          , 
  0xd0          ,   0xa0          ,   0xcb          ,   0xb           ,   0x1b          ,   0x5           ,   0xb4          ,   0x9d          ,   0x6           ,   0xd0          , 
  0x85          ,   0x8d          ,   kScroll_Red   ,   0xc0          ,   0x3a          ,   0xd3          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x63          ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          ,   0x7c          ,   0xa5          ,   0x88          ,   0xa5          , 
};

static uint8 kScroll_d33a[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   0x14          ,   0x4           ,   0x16          ,   kScroll_Green , 
  0x4           ,   0x6           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x67          ,   0xd3          ,   0xe6          ,   0xe5          ,   0x78          , 
  0xa8          ,   0xcb          ,   0xb           ,   kScroll_Red   ,   0x5           ,   0xc4          ,   0x9d          ,   0x57          ,   0xd9          ,   0x22          , 
  0x8f          ,   0xe0          ,   kScroll_Red   ,   0x6f          ,   0xd3          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x71          , 
  0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd1          ,   0xc8          ,   0xa0          ,   0xa5          ,   0xac          ,   0xa5          ,   0xb8          , 
};

static uint8 kScroll_d36f[] = {
  kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x15          ,   0x4           ,   0x19          ,   kScroll_Red   ,   kScroll_Blue  ,   0x4           , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xae          ,   0xd3          ,   0xe6          ,   0xe5          ,   0x4f          ,   0xc6          ,   0xcb          , 
  0xb           ,   kScroll_Red   ,   0x5           ,   0xd4          ,   0x9d          ,   0x9b          ,   0xdd          ,   0xe6          ,   0x8f          ,   kScroll_Red   , 
};

static uint8 kScroll_d3b2[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x16          ,   0x4           ,   0x11          ,   0x11          ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xdd          ,   0xd3          ,   0xe6          ,   0xe5          ,   0xbd          ,   0x86          ,   0xce          , 
  0x15          ,   kScroll_Red   ,   kScroll_Red   ,   0xe4          ,   0x9d          ,   0x14          ,   0xde          ,   0x10          ,   0x90          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x81          ,   0xc5          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd1          ,   0xc8          ,   0xe8          ,   0xa5          ,   0x17          ,   0x4           ,   0x23          ,   0x4           ,   kScroll_Blue  , 
};

static uint8 kScroll_d460[] = {
  kScroll_Green ,   0x1a          ,   0x4           ,   0x12          ,   0x10          ,   0x4           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x88          ,   0xd4          ,   0xe6          ,   0xe5          ,   0x8f          ,   0xde          ,   0xcb          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   , 
  0x44          ,   0x9e          ,   0x3d          ,   0xda          ,   0x52          ,   0x8f          ,   0xc1          ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x95          ,   0xc5          ,   0x5a          ,   0xe2          ,   0xd2          ,   0xc8          , 
  0x3c          ,   0xa6          ,   0x48          ,   0xa6          ,   0x54          ,   0xa6          ,   0x1b          ,   0x4           ,   0x16          ,   0xf           , 
};

static uint8 kScroll_d4bb[] = {
  kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Green ,   0x80          ,   0x1c          ,   0x4           ,   0x17          , 
  0x10          ,   0x3           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xe9          ,   0xd4          ,   0xe6          ,   0xe5          , 
  0x99          ,   0xe8          ,   0xcb          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x64          ,   0x9e          ,   0xd3          ,   0xda          , 
  0x6a          ,   0x8f          ,   0xc1          ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0xdb          ,   0xc5          ,   0x5a          ,   0xe2          ,   0xd2          ,   0xc8          ,   0x84          ,   0xa6          ,   0x90          ,   0xa6          , 
};

static uint8 kScroll_d51a[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x1e          ,   0x4           ,   0x17          ,   0xe           ,   kScroll_Green ,   kScroll_Green , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x45          ,   0xd5          ,   0xe6          ,   0xe5          ,   0x80          ,   0xf5          ,   0xcb          , 
  0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x84          ,   0x9e          ,   0x63          ,   0xdf          ,   0x5e          ,   0x90          ,   kScroll_Red   , 
  kScroll_Red   ,   0x49          ,   0xd5          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xeb          ,   0xc5          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd2          ,   0xc8          ,   0xc0          ,   0xa6          ,   0xcc          ,   0xa6          ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
};

static uint8 kScroll_d549[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x1f          ,   0x4           ,   0x15          ,   0xc           ,   kScroll_Blue  ,   kScroll_Green , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x74          ,   0xd5          ,   0xe6          ,   0xe5          ,   0xc8          ,   0xfe          ,   0xcb          , 
  0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x94          ,   0x9e          ,   0x66          ,   0xdb          ,   0x78          ,   0x8f          ,   kScroll_Red   , 
  kScroll_Red   ,   0x78          ,   0xd5          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xf9          ,   0xc5          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd2          ,   0xc8          ,   0xd8          ,   0xa6          ,   0xe4          ,   0xa6          ,   kScroll_Green ,   kScroll_Green ,   0x20          , 
};

static uint8 kScroll_d578[] = {
  kScroll_Green ,   kScroll_Green ,   0x20          ,   0x4           ,   0x17          ,   0xc           ,   kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xa1          ,   0xd5          ,   0xe6          ,   0xe5          ,   0xb8          ,   0x80          ,   0xcc          ,   0xc           ,   kScroll_Red   , 
  kScroll_Red   ,   0x94          ,   0x9e          ,   0xd9          ,   0xdb          ,   0x86          ,   0x8f          ,   kScroll_Red   ,   kScroll_Red   ,   0xa5          , 
  0xd5          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xfb          ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          , 
  0xc8          ,   0xf0          ,   0xa6          ,   0xfc          ,   0xa6          ,   kScroll_Green ,   kScroll_Green ,   0x21          ,   0x4           ,   0x14          , 
};

static uint8 kScroll_d5a5[] = {
  kScroll_Green ,   kScroll_Green ,   0x21          ,   0x4           ,   0x14          ,   0x9           ,   0x6           ,   0x3           ,   0x90          ,   0xa0          , 
  kScroll_Red   ,   0xce          ,   0xd5          ,   0xe6          ,   0xe5          ,   0xa8          ,   0x82          ,   0xcc          ,   0xc           ,   0x1b          , 
  0x5           ,   0xa4          ,   0x9e          ,   0x57          ,   0xd3          ,   0x1e          ,   0x8e          ,   0xc0          ,   kScroll_Red   ,   0xda          , 
  0xd5          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xfd          ,   0xc5          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          , 
  0xc8          ,   0x8           ,   0xa7          ,   0x14          ,   0xa7          ,   0x20          ,   0xa7          ,   0x2c          ,   0xa7          ,   0x38          , 
};

static uint8 kScroll_d5da[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x22          ,   0x4           , 
  0x1a          ,   0x7           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x13          ,   0xd6          ,   0xe6          , 
  0xe5          ,   0x3b          ,   0xa1          ,   0xcc          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0xb4          ,   0x9e          ,   0x3c          , 
  0xdc          ,   0x94          ,   0x8f          ,   0xc0          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_d642[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x24          ,   0x4           ,   0x1a          ,   0xd           ,   kScroll_Green ,   0x4           , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x6d          ,   0xd6          ,   0xe6          ,   0xe5          ,   0x48          ,   0xac          ,   0xcc          , 
  0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0xd4          ,   0x9e          ,   0x53          ,   0xd4          ,   0x5e          ,   0x8e          ,   kScroll_Red   , 
  0xc0          ,   0x75          ,   0xd6          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x1b          ,   0xc6          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd2          ,   0xc8          ,   0x80          ,   0xa7          ,   0x8c          ,   0xa7          ,   0x98          ,   0xa7          ,   0xa4          , 
};

static uint8 kScroll_d675[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green , 
  0x3           ,   kScroll_Red   ,   0x4           ,   kScroll_Green ,   0x5           ,   kScroll_Red   ,   0x6           ,   kScroll_Blue  ,   0x7           ,   kScroll_Red   , 
  0x80          ,   kScroll_Green ,   kScroll_Red   ,   0x3           ,   kScroll_Green ,   0x4           ,   kScroll_Red   ,   0x5           ,   kScroll_Blue  ,   0x6           , 
  kScroll_Red   ,   0x80          ,   0x5           ,   kScroll_Green ,   0x7           ,   kScroll_Blue  ,   0x80          ,   0x25          ,   0x4           ,   0x1b          , 
  0xe           ,   kScroll_Blue  ,   0x3           ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xc1          ,   0xd6          ,   0xe6          ,   0xe5          , 
};

static uint8 kScroll_d6c5[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   0x80          ,   kScroll_Blue  ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  , 
  0x80          ,   0x26          ,   0x4           ,   0x20          ,   0xf           ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xf7          ,   0xd6          ,   0xe6          ,   0xe5          ,   0x31          ,   0xbd          ,   0xcc          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   , 
  0xf4          ,   0x9e          ,   0x35          ,   0xdd          ,   0xca          ,   0x8f          ,   0xc0          ,   kScroll_Red   ,   0xf9          ,   0xd6          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xe5          ,   0xc6          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          ,   0xc8          , 
};

static uint8 kScroll_d6f9[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   0x27          ,   0x4           ,   0x1a          ,   0xa           ,   0x4           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x24          ,   0xd7          ,   0xe6          ,   0xe5          ,   0x2f          ,   0xc2          ,   0xcc          , 
  0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x4           ,   0x9f          ,   0x38          ,   0xdd          ,   0xd4          ,   0x8f          ,   kScroll_Red   , 
  kScroll_Red   ,   0x26          ,   0xd7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xed          ,   0xc6          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd2          ,   0xc8          ,   0xd4          ,   0xa7          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x28          , 
};

static uint8 kScroll_d726[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x28          ,   0x4           ,   0x22          ,   0x6           ,   0x7           ,   kScroll_Green , 
  0x90          ,   0xa0          ,   kScroll_Red   ,   0x51          ,   0xd7          ,   0xe6          ,   0xe5          ,   0xf1          ,   0xc9          ,   0xcc          , 
  0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x14          ,   0x9f          ,   0x89          ,   0xd0          ,   0x97          ,   0x8d          ,   kScroll_Red   , 
  kScroll_Red   ,   0x57          ,   0xd7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xef          ,   0xc6          ,   kScroll_Red   , 
  kScroll_Red   ,   0xd2          ,   0xc8          ,   0xe0          ,   0xa7          ,   0xec          ,   0xa7          ,   0xf8          ,   0xa7          ,   kScroll_Green , 
};

static uint8 kScroll_d757[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x29          ,   0x4           ,   0x13          ,   0xb           ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x8c          ,   0xd7          ,   0xe6          ,   0xe5          ,   0xcb          ,   0x92          ,   0xce          , 
  0x19          ,   0x1b          ,   0x5           ,   0x24          ,   0x9f          ,   0xc           ,   0xd1          ,   0xa5          ,   0x8d          ,   kScroll_Red   , 
  kScroll_Red   ,   0x8e          ,   0xd7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x3           ,   0xc7          ,   kScroll_Red   , 
};

static uint8 kScroll_d78e[] = {
  kScroll_Blue  ,   0x2a          ,   0x4           ,   0x29          ,   0x7           ,   kScroll_Green ,   0x3           ,   0x90          ,   0xa0          ,   kScroll_Red   , 
  0xd5          ,   0xd7          ,   0x29          ,   0xe6          ,   kScroll_Blue  ,   0xbb          ,   0xd7          ,   0xe6          ,   0xe5          ,   0xb1          , 
  0xe5          ,   0xcc          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x34          ,   0x9f          ,   0xf           ,   0xd1          ,   0xaf          , 
  0x8d          ,   kScroll_Red   ,   0xc0          ,   0xd9          ,   0xd7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xb           , 
  0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          ,   0xc8          ,   0xb1          ,   0xe5          ,   0xcc          ,   0xc           ,   0x1b          , 
};

static uint8 kScroll_d7d9[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  0x80          ,   0x2b          ,   0x4           ,   0x1a          ,   0x8           ,   0x7           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xb           ,   0xd8          ,   0xe6          ,   0xe5          ,   0xc           ,   0xee          ,   0xcc          ,   0xc           ,   0x1b          ,   0x5           , 
  0x44          ,   0x9f          ,   0x12          ,   0xd1          ,   0xb9          ,   0x8d          ,   0xc0          ,   kScroll_Red   ,   0x13          ,   0xd8          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x55          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          ,   0xc8          , 
};

static uint8 kScroll_d813[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0x2c          ,   0x4           ,   0x29          , 
  0x6           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x41          ,   0xd8          ,   0xe6          ,   0xe5          , 
  0xf6          ,   0x9e          ,   0xce          ,   0x19          ,   0x1b          ,   0x5           ,   0x54          ,   0x9f          ,   0xb5          ,   0xd1          , 
  0xcf          ,   0x8d          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x5d          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          ,   0xc8          ,   0x7c          ,   0xa8          ,   0x88          ,   0xa8          , 
};

static uint8 kScroll_d897[] = {
  kScroll_Green ,   0x2f          ,   0x4           ,   0x1c          ,   0x9           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xbf          ,   0xd8          ,   0xe6          ,   0xe5          ,   0x88          ,   0xfb          ,   0xcc          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   , 
  0x74          ,   0x9f          ,   0xee          ,   0xd1          ,   0xf1          ,   0x8d          ,   kScroll_Red   ,   kScroll_Red   ,   0xc3          ,   0xd8          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x6f          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   0xd2          ,   0xc8          , 
  0xac          ,   0xa8          ,   0xb8          ,   0xa8          ,   kScroll_Green ,   kScroll_Green ,   0x30          ,   0x4           ,   0x1c          ,   0xf           , 
};

static uint8 kScroll_d8c3[] = {
  kScroll_Green ,   kScroll_Green ,   0x30          ,   0x4           ,   0x1c          ,   0xf           ,   0x4           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xb           ,   0xd9          ,   0x12          ,   0xe6          ,   0xd           ,   0xf1          ,   0xd8          ,   0xe6          ,   0xe5          , 
  0x75          ,   0xfd          ,   0xcc          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x84          ,   0x9f          ,   0x81          ,   0xd2          , 
  0xff          ,   0x8d          ,   0xc0          ,   kScroll_Red   ,   0xf           ,   0xd9          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x71          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   0xd3          ,   0xc8          ,   0x4           ,   0x84          ,   0xcd          ,   0xc           , 
};

static uint8 kScroll_d90f[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x31          ,   0x4           ,   0x21          ,   0x6           ,   0x5           ,   0x3           , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x3a          ,   0xd9          ,   0xe6          ,   0xe5          ,   0x37          ,   0x8a          ,   0xcd          , 
  0xc           ,   kScroll_Red   ,   kScroll_Red   ,   0x94          ,   0x9f          ,   0x2d          ,   0xcf          ,   0x53          ,   0x8d          ,   kScroll_Red   , 
  kScroll_Red   ,   0x42          ,   0xd9          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x73          ,   0xc7          ,   kScroll_Red   , 
  kScroll_Red   ,   0xdc          ,   0xc8          ,   0xdc          ,   0xa8          ,   0xe8          ,   0xa8          ,   0xf4          ,   0xa8          ,   kScroll_Red   , 
};

static uint8 kScroll_d942[] = {
  kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Green ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Blue  ,   kScroll_Red   ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x5           ,   kScroll_Red   ,   0xb           ,   kScroll_Blue  ,   0x80          , 
  0x5           ,   kScroll_Blue  ,   0xb           ,   kScroll_Red   ,   0x80          ,   0xa           ,   kScroll_Blue  ,   0x80          ,   0x32          ,   0x4           , 
  0x18          ,   0x8           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0xa4          ,   0xd9          ,   0x29          , 
  0xe6          ,   kScroll_Green ,   0x8a          ,   0xd9          ,   0xe6          ,   0xe5          ,   0xe           ,   0x95          ,   0xcd          ,   0xc           , 
};

static uint8 kScroll_d9a8[] = {
  kScroll_Blue  ,   kScroll_Red   ,   0x33          ,   0x4           ,   0x26          ,   0xa           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xd1          ,   0xd9          ,   0xe6          ,   0xe5          ,   0x1e          ,   0x99          ,   0xcd          ,   0xc           ,   kScroll_Red   , 
  0x3           ,   0xb4          ,   0x9f          ,   0x50          ,   0xd4          ,   0x54          ,   0x8e          ,   kScroll_Red   ,   kScroll_Red   ,   0xd3          , 
  0xd9          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xa7          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   0xdc          , 
  0xc8          ,   0x24          ,   0xa9          ,   kScroll_Blue  ,   0x34          ,   0x4           ,   0x2a          ,   0x6           ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_d9d3[] = {
  kScroll_Blue  ,   0x34          ,   0x4           ,   0x2a          ,   0x6           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xfb          ,   0xd9          ,   0xe6          ,   0xe5          ,   0xdc          ,   0x98          ,   0xce          ,   0x17          ,   kScroll_Red   ,   kScroll_Red   , 
  0xc4          ,   0x9f          ,   0x11          ,   0xde          ,   0x6           ,   0x90          ,   kScroll_Red   ,   kScroll_Red   ,   0xfd          ,   0xd9          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xaf          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x30          ,   0xa9          ,   kScroll_Blue  ,   0x35          ,   0x4           ,   0x1b          ,   0x6           ,   kScroll_Blue  ,   kScroll_Green ,   0x70          , 
};

static uint8 kScroll_d9fd[] = {
  kScroll_Blue  ,   0x35          ,   0x4           ,   0x1b          ,   0x6           ,   kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x25          ,   0xda          ,   0xe6          ,   0xe5          ,   0x28          ,   0x9b          ,   0xcd          ,   0xc           ,   kScroll_Red   ,   kScroll_Red   , 
  0xd4          ,   0x9f          ,   0xd9          ,   0xdf          ,   0x7a          ,   0x90          ,   kScroll_Red   ,   0xc0          ,   0x29          ,   0xda          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xb7          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x3c          ,   0xa9          ,   0x48          ,   0xa9          ,   kScroll_Green ,   kScroll_Blue  ,   0x36          ,   0x4           ,   0x1c          ,   0x6           , 
};

static uint8 kScroll_da29[] = {
  kScroll_Green ,   kScroll_Blue  ,   0x36          ,   0x4           ,   0x1c          ,   0x6           ,   0x5           ,   kScroll_Green ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x52          ,   0xda          ,   0xe6          ,   0xe5          ,   0xd           ,   0xa0          ,   0xcd          ,   0xc           ,   kScroll_Red   , 
  kScroll_Red   ,   0xe4          ,   0x9f          ,   0x1c          ,   0xe0          ,   0x8c          ,   0x90          ,   kScroll_Red   ,   kScroll_Red   ,   0x56          , 
  0xda          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xb9          ,   0xc7          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   0x54          ,   0xa9          ,   0x60          ,   0xa9          ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
};

static uint8 kScroll_da56[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  0x37          ,   0x4           ,   0x27          ,   0x9           ,   kScroll_Green ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Blue  ,   0xa6          , 
  0xda          ,   0x29          ,   0xe6          ,   kScroll_Blue  ,   0x8c          ,   0xda          ,   0xe6          ,   0xe5          ,   0x9d          ,   0xb1          , 
  0xcd          ,   0x1c          ,   0x24          ,   0x5           ,   0xf4          ,   0x9f          ,   0x14          ,   0xd3          ,   0x10          ,   0x8e          , 
  kScroll_Blue  ,   kScroll_Blue  ,   0xaa          ,   0xda          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xbb          ,   0xc7          , 
};

static uint8 kScroll_daaa[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Red   ,   0x5           ,   0x14          ,   0x9           ,   kScroll_Blue  ,   0x4           , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xd5          ,   0xda          ,   0xe6          ,   0xe5          ,   0xfe          ,   0xc4          ,   0xcd          , 
  0xd           ,   0x1e          ,   0x5           ,   0x4           ,   0xa0          ,   0x2d          ,   0xe4          ,   0x3e          ,   0x91          ,   kScroll_Blue  , 
  0xc1          ,   0xdd          ,   0xda          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xe1          ,   0xc7          ,   0xe8          , 
  0xe3          ,   0xa           ,   0xc9          ,   0x84          ,   0xa9          ,   0x90          ,   0xa9          ,   0x8a          ,   0xa1          ,   0x9c          , 
};

static uint8 kScroll_dadd[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   0x5           ,   0xe           ,   0xc           ,   0x6           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x27          ,   0xdb          ,   0x12          ,   0xe6          ,   0x10          ,   0xd           ,   0xdb          , 
  0xe6          ,   0xe5          ,   0xdc          ,   0xc8          ,   0xcd          ,   0xd           ,   kScroll_Red   ,   kScroll_Red   ,   0x14          ,   0xa0          , 
  0xd8          ,   0xe1          ,   0xcc          ,   0x90          ,   0xc1          ,   0xc1          ,   0x2b          ,   0xdb          ,   kScroll_Red   ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   0xe9          ,   0xc7          ,   0x3           ,   0xe4          ,   0x1e          ,   0xc9          ,   0xdc          ,   0xc8          , 
};

static uint8 kScroll_db2b[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Green ,   0x5           ,   0xd           ,   0xc           , 
  kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x77          ,   0xdb          ,   0x12          ,   0xe6          ,   0x11          , 
  0x5d          ,   0xdb          ,   0xe6          ,   0xe5          ,   0xa0          ,   0xcd          ,   0xcd          ,   0xd           ,   kScroll_Red   ,   kScroll_Red   , 
  0x24          ,   0xa0          ,   0x40          ,   0xe4          ,   0x48          ,   0x91          ,   0xc1          ,   0xc1          ,   0x7b          ,   0xdb          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0xf7          ,   0xc7          ,   0xe8          ,   0xe3          ,   0x1e          ,   0xc9          , 
};

static uint8 kScroll_db7b[] = {
  kScroll_Green ,   kScroll_Green ,   0x3           ,   0x5           ,   0xe           ,   0xd           ,   0x6           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xc3          ,   0xdb          ,   0x12          ,   0xe6          ,   0x12          ,   0xa9          ,   0xdb          ,   0xe6          ,   0xe5          , 
  0x2d          ,   0xd0          ,   0xcd          ,   0xd           ,   kScroll_Red   ,   kScroll_Red   ,   0x34          ,   0xa0          ,   0x94          ,   0xe7          , 
  0xf8          ,   0x91          ,   0xc1          ,   0xc1          ,   0xc7          ,   0xdb          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x5           ,   0xc8          ,   0x3           ,   0xe4          ,   0x1e          ,   0xc9          ,   0x2d          ,   0xd0          ,   0xcd          ,   0xd           , 
};

static uint8 kScroll_dbc7[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x4           ,   0x5           ,   0x14          ,   0xd           , 
  kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x13          ,   0xdc          ,   0x12          ,   0xe6          ,   0x13          , 
  0xf9          ,   0xdb          ,   0xe6          ,   0xe5          ,   0xe5          ,   0xd3          ,   0xcd          ,   0xd           ,   0x1e          ,   0x5           , 
  0x44          ,   0xa0          ,   0xa3          ,   0xe4          ,   0x5a          ,   0x91          ,   0xc1          ,   0xc1          ,   0x17          ,   0xdc          , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x13          ,   0xc8          ,   0xe8          ,   0xe3          ,   0x1e          ,   0xc9          , 
};

static uint8 kScroll_dc17[] = {
  kScroll_Green ,   kScroll_Green ,   0x5           ,   0x5           ,   0x13          ,   0xf           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x5f          ,   0xdc          ,   0x12          ,   0xe6          ,   0x14          ,   0x45          ,   0xdc          ,   0xe6          ,   0xe5          , 
  0xeb          ,   0xd5          ,   0xcd          ,   0xd           ,   0x45          ,   0x6           ,   0x54          ,   0xa0          ,   0x87          ,   0xe3          , 
  0x22          ,   0x91          ,   0xc1          ,   0xc1          ,   0x63          ,   0xdc          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x21          ,   0xc8          ,   0x1e          ,   0xe4          ,   0x1e          ,   0xc9          ,   0xeb          ,   0xd5          ,   0xcd          ,   0xd           , 
};

static uint8 kScroll_dc63[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   0x6           ,   0x5           ,   0x11          ,   0xf           ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xab          ,   0xdc          ,   0x12          ,   0xe6          ,   0x14          ,   0x91          ,   0xdc          ,   0xe6          ,   0xe5          , 
  0xc4          ,   0xd7          ,   0xcd          ,   0xd           ,   0x45          ,   0x6           ,   0x64          ,   0xa0          ,   0x5b          ,   0xe2          , 
  0xde          ,   0x90          ,   0xc1          ,   0xc1          ,   0xaf          ,   0xdc          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x23          ,   0xc8          ,   0x1e          ,   0xe4          ,   0x1e          ,   0xc9          ,   0xc4          ,   0xd7          ,   0xcd          ,   0xd           , 
};

static uint8 kScroll_dcaf[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   0x7           ,   0x5           ,   0xd           ,   0xf           ,   0x4           ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xf7          ,   0xdc          ,   0x12          ,   0xe6          ,   0x14          ,   0xdd          ,   0xdc          ,   0xe6          ,   0xe5          , 
  0x30          ,   0xd9          ,   0xcd          ,   0xd           ,   kScroll_Red   ,   kScroll_Red   ,   0x74          ,   0xa0          ,   0x6e          ,   0xe2          , 
  0xec          ,   0x90          ,   0xc1          ,   0xc1          ,   0xfb          ,   0xdc          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
  0x31          ,   0xc8          ,   0x1e          ,   0xe4          ,   0x1e          ,   0xc9          ,   0x30          ,   0xd9          ,   0xcd          ,   0xd           , 
};

static uint8 kScroll_dcfb[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x8           ,   0x5           ,   0xc           ,   0xf           ,   kScroll_Blue  ,   kScroll_Green , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x26          ,   0xdd          ,   0xe6          ,   0xe5          ,   0xf8          ,   0xdb          ,   0xcd          , 
  0xd           ,   0x1e          ,   0x5           ,   0x84          ,   0xa0          ,   0x8           ,   0xe7          ,   0xc4          ,   0x91          ,   0xc1          , 
  0xc1          ,   0x2c          ,   0xdd          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x39          ,   0xc8          ,   0x1e          , 
  0xe4          ,   0x1e          ,   0xc9          ,   0x50          ,   0xaa          ,   0x5c          ,   0xaa          ,   0x68          ,   0xaa          ,   kScroll_Green , 
};

static uint8 kScroll_dd2c[] = {
  kScroll_Green ,   kScroll_Green ,   0x9           ,   0x5           ,   0xb           ,   0x10          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x55          ,   0xdd          ,   0xe6          ,   0xe5          ,   0x23          ,   0xa8          ,   0xce          ,   0x18          ,   kScroll_Red   , 
  kScroll_Red   ,   0x94          ,   0xa0          ,   0xb           ,   0xe7          ,   0xce          ,   0x91          ,   kScroll_Red   ,   kScroll_Red   ,   0x57          , 
  0xdd          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x41          ,   0xc8          ,   kScroll_Red   ,   kScroll_Red   ,   0x1e          , 
  0xc9          ,   0x74          ,   0xaa          ,   kScroll_Blue  ,   0xa           ,   0x5           ,   0xd           ,   0x12          ,   0x4           ,   kScroll_Blue  , 
};

static uint8 kScroll_dd57[] = {
  kScroll_Blue  ,   0xa           ,   0x5           ,   0xd           ,   0x12          ,   0x4           ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0xbc          ,   0xdd          ,   0xff          ,   0xe5          ,   0xa2          ,   0xdd          ,   0x12          ,   0xe6          ,   kScroll_Green ,   0x88          , 
  0xdd          ,   0xe6          ,   0xe5          ,   0xde          ,   0xde          ,   0xcd          ,   0xe           ,   kScroll_Red   ,   kScroll_Red   ,   0xa4          , 
  0xa0          ,   0x21          ,   0xe3          ,   kScroll_Green ,   0x91          ,   0xc1          ,   0xc1          ,   0xc0          ,   0xdd          ,   kScroll_Red   , 
  kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x4f          ,   0xc8          ,   0x8a          ,   0xe4          ,   0x1e          ,   0xc9          ,   0xde          , 
};

static uint8 kScroll_ddc0[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0xb           ,   0x5           ,   0xd           ,   0x10          ,   0x4           ,   kScroll_Blue  , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0xeb          ,   0xdd          ,   0xe6          ,   0xe5          ,   0xf           ,   0xe2          ,   0xcd          , 
  0xd           ,   kScroll_Red   ,   kScroll_Red   ,   0xd4          ,   0xa0          ,   0x84          ,   0xe3          ,   0x18          ,   0x91          ,   0xc1          , 
  0xc1          ,   0xef          ,   0xdd          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x57          ,   0xc8          ,   0x1e          , 
  0xe4          ,   0x1e          ,   0xc9          ,   0x98          ,   0xaa          ,   0xa4          ,   0xaa          ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
};

static uint8 kScroll_ddef[] = {
  kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0xc           ,   0x5           ,   0x11          ,   0x10          ,   kScroll_Blue  ,   0x3           , 
  0x70          ,   0xa0          ,   kScroll_Red   ,   0x1a          ,   0xde          ,   0xe6          ,   0xe5          ,   0x18          ,   0xe5          ,   0xcd          , 
  0xd           ,   0x1e          ,   0x5           ,   0xe4          ,   0xa0          ,   0x57          ,   0xe8          ,   0xa           ,   0x92          ,   0xc1          , 
  0xc1          ,   0x20          ,   0xde          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x6b          ,   0xc8          ,   0x54          , 
  0xe4          ,   0x1e          ,   0xc9          ,   0xb0          ,   0xaa          ,   0xbc          ,   0xaa          ,   0xc8          ,   0xaa          ,   kScroll_Green , 
};

static uint8 kScroll_de20[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   0xd           ,   0x5           ,   0x10          ,   0x11          ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          , 
  0xa0          ,   kScroll_Red   ,   0x4a          ,   0xde          ,   0xe6          ,   0xe5          ,   0xcb          ,   0x92          ,   0xce          ,   0x19          , 
  0x1e          ,   0x5           ,   0xf4          ,   0xa0          ,   0xd5          ,   0xe1          ,   0xc2          ,   0x90          ,   kScroll_Red   ,   kScroll_Red   , 
  0x4c          ,   0xde          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x73          ,   0xc8          ,   kScroll_Red   ,   kScroll_Red   , 
  0x1e          ,   0xc9          ,   0xd4          ,   0xaa          ,   kScroll_Blue  ,   0xe           ,   0x5           ,   0xb           ,   0x12          ,   kScroll_Green , 
};

static uint8 kScroll_de4c[] = {
  kScroll_Blue  ,   0xe           ,   0x5           ,   0xb           ,   0x12          ,   kScroll_Green ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   , 
  0x74          ,   0xde          ,   0xe6          ,   0xe5          ,   0x14          ,   0xe9          ,   0xcd          ,   0xd           ,   0x24          ,   0x7           , 
  0x4           ,   0xa1          ,   0xaa          ,   0xe3          ,   0x30          ,   0x91          ,   0xc1          ,   0xc1          ,   0x78          ,   0xde          , 
  kScroll_Red   ,   kScroll_Red   ,   0xa0          ,   0xe5          ,   0x7b          ,   0xc8          ,   0x39          ,   0xe4          ,   0x1f          ,   0xc9          , 
  0xe0          ,   0xaa          ,   0xec          ,   0xaa          ,   kScroll_Green ,   kScroll_Green ,   0xf           ,   0x5           ,   0xb           ,   0x13          , 
};

static uint8 kScroll_de78[] = {
  kScroll_Green ,   kScroll_Green ,   0xf           ,   0x5           ,   0xb           ,   0x13          ,   kScroll_Blue  ,   kScroll_Green ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xa1          ,   0xde          ,   0xe6          ,   0xe5          ,   0x5b          ,   0xeb          ,   0xcd          ,   0xd           ,   kScroll_Red   , 
  kScroll_Red   ,   0x14          ,   0xa1          ,   0x9c          ,   0xe5          ,   0x88          ,   0x91          ,   0xc1          ,   0xc1          ,   0xa5          , 
  0xde          ,   kScroll_Red   ,   kScroll_Red   ,   0x7c          ,   0xe5          ,   0x89          ,   0xc8          ,   0x54          ,   0xe4          ,   0x33          , 
  0xc9          ,   0xf8          ,   0xaa          ,   0x4           ,   0xab          ,   kScroll_Green ,   kScroll_Blue  ,   0x10          ,   0x5           ,   0xc           , 
};

static uint8 kScroll_dea5[] = {
  kScroll_Green ,   kScroll_Blue  ,   0x10          ,   0x5           ,   0xc           ,   0x13          ,   0x6           ,   kScroll_Green ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0xce          ,   0xde          ,   0xe6          ,   0xe5          ,   0x7a          ,   0xed          ,   0xcd          ,   0xd           ,   kScroll_Red   , 
  kScroll_Red   ,   0x24          ,   0xa1          ,   0x95          ,   0xe6          ,   0xb2          ,   0x91          ,   0xc1          ,   0xc1          ,   0xd2          , 
  0xde          ,   kScroll_Red   ,   kScroll_Red   ,   0xa0          ,   0xe5          ,   0x97          ,   0xc8          ,   0x6f          ,   0xe4          ,   0x46          , 
  0xc9          ,   0x10          ,   0xab          ,   0x1c          ,   0xab          ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
};

static uint8 kScroll_ded2[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  , 
  kScroll_Blue  ,   kScroll_Blue  ,   0x11          ,   0x5           ,   0x12          ,   0x10          ,   0x3           ,   0x6           ,   0x70          ,   0xa0          , 
  kScroll_Red   ,   0x5           ,   0xdf          ,   0xe6          ,   0xe5          ,   0x34          ,   0xf5          ,   0xcd          ,   0xd           ,   kScroll_Red   , 
  kScroll_Red   ,   0x34          ,   0xa1          ,   kScroll_Green ,   0xe1          ,   0xb0          ,   0x90          ,   0xc1          ,   0xc1          ,   0x9           , 
  0xdf          ,   kScroll_Red   ,   kScroll_Red   ,   0xa4          ,   0xe5          ,   0xa5          ,   0xc8          ,   0x6f          ,   0xe4          ,   0x53          , 
};

static uint8 kScroll_df09[] = {
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green , 
  kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Green ,   kScroll_Blue  ,   kScroll_Blue  ,   kScroll_Blue  ,   0x12          ,   0x5           , 
  0x15          ,   0xc           ,   kScroll_Blue  ,   kScroll_Blue  ,   0x70          ,   0xa0          ,   kScroll_Red   ,   0x42          ,   0xdf          ,   0xe6          , 
  0xe5          ,   0xc2          ,   0x95          ,   0xce          ,   0x19          ,   0x1e          ,   0x5           ,   0x44          ,   0xa1          ,   0x91          , 
  0xe7          ,   0xee          ,   0x91          ,   kScroll_Red   ,   kScroll_Red   ,   0x44          ,   0xdf          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   , 
};

static uint8 kScroll_df44[] = {
  kScroll_Blue  ,   kScroll_Red   ,   0x6           ,   0xc           ,   0xd           ,   kScroll_Blue  ,   0x3           ,   0x70          ,   0xa0          ,   0x5           , 
  0x8b          ,   0xdf          ,   0x29          ,   0xe6          ,   kScroll_Blue  ,   0x71          ,   0xdf          ,   0xe6          ,   0xe5          ,   0x46          , 
  0xb8          ,   0xcd          ,   0x11          ,   0x2d          ,   0x6           ,   0x46          ,   0xa1          ,   0x8a          ,   0xe8          ,   0x18          , 
  0x92          ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   kScroll_Red   ,   0x1f          ,   0xe5          ,   0xbb          , 
  0xc8          ,   0xd4          ,   0xe1          ,   0x76          ,   0xc9          ,   0x46          ,   0xb8          ,   0xcd          ,   0x12          ,   kScroll_Red   , 
};

uint8* get_Scrolls(uint16 scroll_ptr) {
  switch (scroll_ptr) {
    case 0x9283: return kScroll_9283;
    case 0x9370: return kScroll_9370;
    case 0x93d3: return kScroll_93d3;
    case 0x9431: return kScroll_9431;
    case 0x94b9: return kScroll_94b9;
    case 0x94f9: return kScroll_94f9;
    case 0x9528: return kScroll_9528;
    case 0x95d3: return kScroll_95d3;
    case 0x9657: return kScroll_9657;
    case 0x9686: return kScroll_9686;
    case 0x9729: return kScroll_9729;
    case 0x97a5: return kScroll_97a5;
    case 0x9800: return kScroll_9800;
    case 0x9965: return kScroll_9965;
    case 0x99ec: return kScroll_99ec;
    case 0x9a24: return kScroll_9a24;
    case 0x9a8e: return kScroll_9a8e;
    case 0x9ad8: return kScroll_9ad8;
    case 0x9b16: return kScroll_9b16;
    case 0x9b86: return kScroll_9b86;
    case 0x9bf3: return kScroll_9bf3;
    case 0x9c30: return kScroll_9c30;
    case 0x9cb2: return kScroll_9cb2;
    case 0x9ce0: return kScroll_9ce0;
    case 0x9d52: return kScroll_9d52;
    case 0x9e3c: return kScroll_9e3c;
    case 0x9e7f: return kScroll_9e7f;
    case 0x9eed: return kScroll_9eed;
    case 0x9f5d: return kScroll_9f5d;
    case 0x9fae: return kScroll_9fae;
    case 0xa010: return kScroll_a010;
    case 0xa040: return kScroll_a040;
    case 0xa07a: return kScroll_a07a;
    case 0xa0cf: return kScroll_a0cf;
    case 0xa0fd: return kScroll_a0fd;
    case 0xa284: return kScroll_a284;
    case 0xa2be: return kScroll_a2be;
    case 0xa357: return kScroll_a357;
    case 0xa3a5: return kScroll_a3a5;
    case 0xa3d7: return kScroll_a3d7;
    case 0xa435: return kScroll_a435;
    case 0xa470: return kScroll_a470;
    case 0xa49e: return kScroll_a49e;
    case 0xa507: return kScroll_a507;
    case 0xa598: return kScroll_a598;
    case 0xa5e9: return kScroll_a5e9;
    case 0xa697: return kScroll_a697;
    case 0xa6d0: return kScroll_a6d0;
    case 0xa844: return kScroll_a844;
    case 0xa8e6: return kScroll_a8e6;
    case 0xa954: return kScroll_a954;
    case 0xa9d7: return kScroll_a9d7;
    case 0xaa39: return kScroll_aa39;
    case 0xaa6c: return kScroll_aa6c;
    case 0xaab1: return kScroll_aab1;
    case 0xab36: return kScroll_ab36;
    case 0xabba: return kScroll_abba;
    case 0xabfd: return kScroll_abfd;
    case 0xac56: return kScroll_ac56;
    case 0xacae: return kScroll_acae;
    case 0xace8: return kScroll_ace8;
    case 0xad8f: return kScroll_ad8f;
    case 0xadda: return kScroll_adda;
    case 0xae5d: return kScroll_ae5d;
    case 0xaea3: return kScroll_aea3;
    case 0xaf0c: return kScroll_af0c;
    case 0xaf6e: return kScroll_af6e;
    case 0xaf9f: return kScroll_af9f;
    case 0xb0a5: return kScroll_b0a5;
    case 0xb131: return kScroll_b131;
    case 0xb164: return kScroll_b164;
    case 0xb1e4: return kScroll_b1e4;
    case 0xb210: return kScroll_b210;
    case 0xb265: return kScroll_b265;
    case 0xb2cd: return kScroll_b2cd;
    case 0xb378: return kScroll_b378;
    case 0xb3d6: return kScroll_b3d6;
    case 0xb435: return kScroll_b435;
    case 0xb4da: return kScroll_b4da;
    case 0xb53d: return kScroll_b53d;
    case 0xb5b4: return kScroll_b5b4;
    case 0xb600: return kScroll_b600;
    case 0xb681: return kScroll_b681;
    case 0xb71b: return kScroll_b71b;
    case 0xc9da: return kScroll_c9da;
    case 0xca9e: return kScroll_ca9e;
    case 0xcb4a: return kScroll_cb4a;
    case 0xcc21: return kScroll_cc21;
    case 0xccbb: return kScroll_ccbb;
    case 0xcd5b: return kScroll_cd5b;
    case 0xcda6: return kScroll_cda6;
    case 0xcdf0: return kScroll_cdf0;
    case 0xce39: return kScroll_ce39;
    case 0xcf49: return kScroll_cf49;
    case 0xcf7f: return kScroll_cf7f;
    case 0xcfad: return kScroll_cfad;
    case 0xcffa: return kScroll_cffa;
    case 0xd046: return kScroll_d046;
    case 0xd07e: return kScroll_d07e;
    case 0xd0b5: return kScroll_d0b5;
    case 0xd0ec: return kScroll_d0ec;
    case 0xd12f: return kScroll_d12f;
    case 0xd164: return kScroll_d164;
    case 0xd198: return kScroll_d198;
    case 0xd1d0: return kScroll_d1d0;
    case 0xd20a: return kScroll_d20a;
    case 0xd24b: return kScroll_d24b;
    case 0xd27d: return kScroll_d27d;
    case 0xd2a9: return kScroll_d2a9;
    case 0xd2d3: return kScroll_d2d3;
    case 0xd304: return kScroll_d304;
    case 0xd33a: return kScroll_d33a;
    case 0xd36f: return kScroll_d36f;
    case 0xd3b2: return kScroll_d3b2;
    case 0xd460: return kScroll_d460;
    case 0xd4bb: return kScroll_d4bb;
    case 0xd51a: return kScroll_d51a;
    case 0xd549: return kScroll_d549;
    case 0xd578: return kScroll_d578;
    case 0xd5a5: return kScroll_d5a5;
    case 0xd5da: return kScroll_d5da;
    case 0xd642: return kScroll_d642;
    case 0xd675: return kScroll_d675;
    case 0xd6c5: return kScroll_d6c5;
    case 0xd6f9: return kScroll_d6f9;
    case 0xd726: return kScroll_d726;
    case 0xd757: return kScroll_d757;
    case 0xd78e: return kScroll_d78e;
    case 0xd7d9: return kScroll_d7d9;
    case 0xd813: return kScroll_d813;
    case 0xd897: return kScroll_d897;
    case 0xd8c3: return kScroll_d8c3;
    case 0xd90f: return kScroll_d90f;
    case 0xd942: return kScroll_d942;
    case 0xd9a8: return kScroll_d9a8;
    case 0xd9d3: return kScroll_d9d3;
    case 0xd9fd: return kScroll_d9fd;
    case 0xda29: return kScroll_da29;
    case 0xda56: return kScroll_da56;
    case 0xdaaa: return kScroll_daaa;
    case 0xdadd: return kScroll_dadd;
    case 0xdb2b: return kScroll_db2b;
    case 0xdb7b: return kScroll_db7b;
    case 0xdbc7: return kScroll_dbc7;
    case 0xdc17: return kScroll_dc17;
    case 0xdc63: return kScroll_dc63;
    case 0xdcaf: return kScroll_dcaf;
    case 0xdcfb: return kScroll_dcfb;
    case 0xdd2c: return kScroll_dd2c;
    case 0xdd57: return kScroll_dd57;
    case 0xddc0: return kScroll_ddc0;
    case 0xddef: return kScroll_ddef;
    case 0xde20: return kScroll_de20;
    case 0xde4c: return kScroll_de4c;
    case 0xde78: return kScroll_de78;
    case 0xdea5: return kScroll_dea5;
    case 0xded2: return kScroll_ded2;
    case 0xdf09: return kScroll_df09;
    case 0xdf44: return kScroll_df44;
    default: Unreachable(); return (uint8*){ 0 };
  }
}


static XraySpecialCasing kXraySpecialCasing_986b[] = {
  [0] = { .x_block = 15, .y_block = 10, .level_data_block = 0x52  , },
  [1] = { .x_block = 15, .y_block = 11, .level_data_block = 0x52  , },
  [2] = { .x_block = 15, .y_block = 12, .level_data_block = 0x52  , },
  [3] = { .x_block =  0, .y_block =  0, },
};

XraySpecialCasing* get_XraySpecialCasing(uint16 xray_special_casing_ptr) {
  switch (xray_special_casing_ptr) {
    case 0x986b: return kXraySpecialCasing_986b;
    default: Unreachable(); return (XraySpecialCasing*){ 0 };
  }
}


RoomPlmEntry get_RoomPlmEntry(uint16 room_plm_header_ptr) {
  switch (room_plm_header_ptr) {
    case 0x8000: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  30, .y_block =  40, .plm_room_argument = 0x92b0,  };
    case 0x8006: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  30, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x800c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  30, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8012: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  30, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x8018: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block = 142, .y_block =  70, .plm_room_argument =    0x0,  };
    case 0x801e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc85a, .x_block = 142, .y_block =  22, .plm_room_argument =    0x1,  };
    case 0x8024: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8026: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  30, .y_block =  40, .plm_room_argument = 0x92b0,  };
    case 0x802c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  30, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x8032: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  30, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8038: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  30, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x803e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0x8,  };
    case 0x8044: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  38, .plm_room_argument = 0x9002,  };
    case 0x804a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block = 142, .y_block =  70, .plm_room_argument = 0x9003,  };
    case 0x8050: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block = 142, .y_block =  22, .plm_room_argument = 0x9004,  };
    case 0x8056: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8058: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x805a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  63, .y_block =  11, .plm_room_argument = 0x9389,  };
    case 0x8060: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  67, .y_block =  11, .plm_room_argument = 0x938c,  };
    case 0x8066: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  22, .y_block =  13, .plm_room_argument = 0x938f,  };
    case 0x806c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8072: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8078: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x807e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  22, .y_block =  11, .plm_room_argument = 0x9396,  };
    case 0x8084: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x808a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8090: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8096: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  14, .y_block =   9, .plm_room_argument = 0x9399,  };
    case 0x809c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  14, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x80a2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  14, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x80a8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  28, .y_block =  10, .plm_room_argument = 0x939c,  };
    case 0x80ae: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x80b4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x80ba: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x80c0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x80c6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x80cc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  50, .y_block =  11, .plm_room_argument = 0x939f,  };
    case 0x80d2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  60, .y_block =  11, .plm_room_argument = 0x939f,  };
    case 0x80d8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  58, .y_block =  17, .plm_room_argument = 0x93a2,  };
    case 0x80de: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  59, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x80e4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  60, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x80ea: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  61, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x80f0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  62, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x80f6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  52, .y_block =  14, .plm_room_argument = 0x93a5,  };
    case 0x80fc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  30, .y_block =  54, .plm_room_argument =    0x5,  };
    case 0x8102: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8104: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  63, .y_block =  11, .plm_room_argument = 0x9389,  };
    case 0x810a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  67, .y_block =  11, .plm_room_argument = 0x938c,  };
    case 0x8110: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  22, .y_block =  13, .plm_room_argument = 0x938f,  };
    case 0x8116: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x811c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8122: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8128: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  22, .y_block =  11, .plm_room_argument = 0x9396,  };
    case 0x812e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8134: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x813a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8140: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  14, .y_block =   9, .plm_room_argument = 0x9399,  };
    case 0x8146: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  14, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x814c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  14, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x8152: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  28, .y_block =  10, .plm_room_argument = 0x939c,  };
    case 0x8158: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x815e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8164: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x816a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x8170: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  28, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x8176: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  50, .y_block =  11, .plm_room_argument = 0x939f,  };
    case 0x817c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  60, .y_block =  11, .plm_room_argument = 0x939f,  };
    case 0x8182: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  58, .y_block =  17, .plm_room_argument = 0x93a2,  };
    case 0x8188: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  59, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x818e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  60, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x8194: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  61, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x819a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  62, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x81a0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  52, .y_block =  14, .plm_room_argument = 0x93a5,  };
    case 0x81a6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0xa,  };
    case 0x81ac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument = 0x9006,  };
    case 0x81b2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =  17, .y_block =  38, .plm_room_argument = 0x9007,  };
    case 0x81b8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =  17, .y_block =  54, .plm_room_argument = 0x9008,  };
    case 0x81be: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =  54, .plm_room_argument = 0x9009,  };
    case 0x81c4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc84e, .x_block =  22, .y_block =  77, .plm_room_argument = 0x900a,  };
    case 0x81ca: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x81cc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =  29, .y_block =   7, .plm_room_argument =    0x0,  };
    case 0x81d2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x81d4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x1,  };
    case 0x81da: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x81dc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  94, .y_block =  54, .plm_room_argument = 0x900b,  };
    case 0x81e2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block = 126, .y_block =  70, .plm_room_argument =    0xc,  };
    case 0x81e8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   2, .y_block =  91, .plm_room_argument =    0x1,  };
    case 0x81ee: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =  28, .y_block =   3, .plm_room_argument =    0x2,  };
    case 0x81f4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   1, .y_block =  47, .plm_room_argument =    0x3,  };
    case 0x81fa: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x81fc: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x81fe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  23, .y_block =  15, .plm_room_argument = 0x94c2,  };
    case 0x8204: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  15, .plm_room_argument = 0x8000,  };
    case 0x820a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  22, .y_block =  12, .plm_room_argument = 0x94c7,  };
    case 0x8210: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8216: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x821c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8222: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc85a, .x_block =  46, .y_block =   6, .plm_room_argument =    0xd,  };
    case 0x8228: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc866, .x_block =  22, .y_block =  45, .plm_room_argument =    0xe,  };
    case 0x822e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8230: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  13, .plm_room_argument = 0x94fa,  };
    case 0x8236: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8238: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x823a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x823c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x823e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc866, .x_block =   6, .y_block =  13, .plm_room_argument =    0xf,  };
    case 0x8244: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8246: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8248: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  14, .y_block =   9, .plm_room_argument =    0x4,  };
    case 0x824e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8250: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  13, .plm_room_argument = 0x9658,  };
    case 0x8256: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc86c, .x_block =   6, .y_block =   2, .plm_room_argument =   0x10,  };
    case 0x825c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x825e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  84, .y_block =  12, .plm_room_argument = 0x968c,  };
    case 0x8264: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =  83, .y_block =   8, .plm_room_argument =    0x5,  };
    case 0x826a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x826c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x826e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  29, .y_block =   5, .plm_room_argument = 0x9747,  };
    case 0x8274: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block =   5, .plm_room_argument = 0x9744,  };
    case 0x827a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  29, .y_block = 118, .plm_room_argument = 0x974d,  };
    case 0x8280: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block = 118, .plm_room_argument = 0x974a,  };
    case 0x8286: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  18, .y_block = 133, .plm_room_argument = 0x8000,  };
    case 0x828c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  19, .y_block = 133, .plm_room_argument = 0x8000,  };
    case 0x8292: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 133, .plm_room_argument = 0x8000,  };
    case 0x8298: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x829e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x82a4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x82aa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  20, .y_block = 137, .plm_room_argument = 0x9753,  };
    case 0x82b0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x82b6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x82bc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x82c2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block = 137, .plm_room_argument = 0x9750,  };
    case 0x82c8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x82ce: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x82d4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x82da: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block = 137, .plm_room_argument = 0x9756,  };
    case 0x82e0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x82e6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x82ec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x82f2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block = 137, .plm_room_argument = 0x9759,  };
    case 0x82f8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  46, .y_block =   6, .plm_room_argument = 0x9011,  };
    case 0x82fe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block = 134, .plm_room_argument = 0x9012,  };
    case 0x8304: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc85a, .x_block =  46, .y_block = 118, .plm_room_argument =   0x13,  };
    case 0x830a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x830c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  29, .y_block =   5, .plm_room_argument = 0x9747,  };
    case 0x8312: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block =   5, .plm_room_argument = 0x9744,  };
    case 0x8318: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  29, .y_block = 118, .plm_room_argument = 0x974d,  };
    case 0x831e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block = 118, .plm_room_argument = 0x974a,  };
    case 0x8324: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  18, .y_block = 133, .plm_room_argument = 0x8000,  };
    case 0x832a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  19, .y_block = 133, .plm_room_argument = 0x8000,  };
    case 0x8330: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 133, .plm_room_argument = 0x8000,  };
    case 0x8336: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x833c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x8342: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x8348: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  20, .y_block = 137, .plm_room_argument = 0x9753,  };
    case 0x834e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x8354: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x835a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x8360: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block = 137, .plm_room_argument = 0x9750,  };
    case 0x8366: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x836c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x8372: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x8378: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block = 137, .plm_room_argument = 0x9756,  };
    case 0x837e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block = 134, .plm_room_argument = 0x8000,  };
    case 0x8384: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block = 135, .plm_room_argument = 0x8000,  };
    case 0x838a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block = 136, .plm_room_argument = 0x8000,  };
    case 0x8390: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block = 137, .plm_room_argument = 0x9759,  };
    case 0x8396: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0xc,  };
    case 0x839c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  46, .y_block =   6, .plm_room_argument = 0x9014,  };
    case 0x83a2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  46, .y_block = 118, .plm_room_argument = 0x9015,  };
    case 0x83a8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block = 134, .plm_room_argument = 0x9016,  };
    case 0x83ae: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block = 134, .plm_room_argument = 0x9017,  };
    case 0x83b4: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x83b6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  15, .plm_room_argument = 0x97ab,  };
    case 0x83bc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   6, .y_block =  15, .plm_room_argument = 0x97ab,  };
    case 0x83c2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =   9, .plm_room_argument = 0x97b0,  };
    case 0x83c8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument = 0x9018,  };
    case 0x83ce: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x83d0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  15, .plm_room_argument = 0x97ab,  };
    case 0x83d6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   6, .y_block =  15, .plm_room_argument = 0x97ab,  };
    case 0x83dc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =   9, .plm_room_argument = 0x97b0,  };
    case 0x83e2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  46, .y_block =   6, .plm_room_argument =  0xc19,  };
    case 0x83e8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xc1a,  };
    case 0x83ee: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   5, .y_block =  26, .plm_room_argument =    0x6,  };
    case 0x83f4: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x83f6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  13, .plm_room_argument = 0x9801,  };
    case 0x83fc: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x83fe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xbaf4, .x_block =   1, .y_block =   6, .plm_room_argument =  0x81b,  };
    case 0x8404: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef3b, .x_block =  12, .y_block =  10, .plm_room_argument =    0x7,  };
    case 0x840a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xd6ea, .x_block =  13, .y_block =  11, .plm_room_argument =    0x0,  };
    case 0x8410: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8412: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0xe,  };
    case 0x8418: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument = 0x181c,  };
    case 0x841e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8420: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  46, .y_block =   6, .plm_room_argument =   0x1d,  };
    case 0x8426: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8428: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =   0x10,  };
    case 0x842e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8430: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8432: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =   7, .y_block =  42, .plm_room_argument =    0x8,  };
    case 0x8438: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x843a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  13, .plm_room_argument = 0x9966,  };
    case 0x8440: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8442: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8444: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6d3, .x_block =  11, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x844a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x844c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  67, .plm_room_argument = 0x99f3,  };
    case 0x8452: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  67, .plm_room_argument = 0x8000,  };
    case 0x8458: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   9, .y_block =  70, .plm_room_argument = 0x99f6,  };
    case 0x845e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  70, .plm_room_argument = 0x8000,  };
    case 0x8464: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  13, .y_block =  27, .plm_room_argument =    0x9,  };
    case 0x846a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   2, .y_block =  27, .plm_room_argument =    0xa,  };
    case 0x8470: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block = 102, .plm_room_argument =   0x1e,  };
    case 0x8476: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8478: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =  59, .y_block =   9, .plm_room_argument =    0xb,  };
    case 0x847e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8480: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8482: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8484: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8486: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   4, .y_block =   7, .plm_room_argument =    0xc,  };
    case 0x848c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x848e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block = 113, .plm_room_argument = 0x9b46,  };
    case 0x8494: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block = 168, .plm_room_argument = 0x9b4b,  };
    case 0x849a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  33, .y_block = 168, .plm_room_argument = 0x9b4b,  };
    case 0x84a0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block = 172, .plm_room_argument = 0x9b52,  };
    case 0x84a6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb70b, .x_block =   6, .y_block =  44, .plm_room_argument = 0x8000,  };
    case 0x84ac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef37, .x_block =  60, .y_block = 122, .plm_room_argument =    0xd,  };
    case 0x84b2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =  86, .plm_room_argument =   0x1f,  };
    case 0x84b8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =  70, .plm_room_argument =   0x20,  };
    case 0x84be: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  70, .plm_room_argument =   0x21,  };
    case 0x84c4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block = 102, .plm_room_argument =   0x22,  };
    case 0x84ca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block = 102, .plm_room_argument =   0x23,  };
    case 0x84d0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  14, .y_block = 118, .plm_room_argument = 0x9024,  };
    case 0x84d6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x84d8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  23, .y_block =  11, .plm_room_argument = 0x9b98,  };
    case 0x84de: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x84e4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef33, .x_block =  26, .y_block = 135, .plm_room_argument =    0xe,  };
    case 0x84ea: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x84ec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  46, .y_block =   6, .plm_room_argument =  0xc25,  };
    case 0x84f2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x84f4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  41, .y_block =  14, .plm_room_argument = 0x9bf9,  };
    case 0x84fa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  42, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x8500: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  43, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x8506: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  19, .plm_room_argument = 0x9c00,  };
    case 0x850c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  15, .plm_room_argument = 0x9bf9,  };
    case 0x8512: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  46, .y_block =  22, .plm_room_argument =   0x26,  };
    case 0x8518: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  19, .y_block =  27, .plm_room_argument =    0xf,  };
    case 0x851e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =   4, .y_block =   6, .plm_room_argument =   0x10,  };
    case 0x8524: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8526: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  14, .y_block =  11, .plm_room_argument = 0x9c32,  };
    case 0x852c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7b, .x_block =  11, .y_block =   7, .plm_room_argument =   0x11,  };
    case 0x8532: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =  30, .y_block =   7, .plm_room_argument =   0x12,  };
    case 0x8538: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  25, .y_block =   7, .plm_room_argument =   0x13,  };
    case 0x853e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8540: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6d3, .x_block =   5, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8546: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8548: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block =  38, .plm_room_argument =   0x27,  };
    case 0x854e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8550: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6eb, .x_block =   4, .y_block =  10, .plm_room_argument =   0x14,  };
    case 0x8556: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8558: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb643, .x_block =  69, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x855e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  69, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8564: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  70, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x856a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  71, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8570: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  72, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x8576: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63f, .x_block =  73, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x857c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  74, .y_block =  13, .plm_room_argument = 0x9d11,  };
    case 0x8582: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  64, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8588: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  64, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x858e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  64, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8594: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  64, .y_block =  11, .plm_room_argument = 0x9d14,  };
    case 0x859a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb643, .x_block =  75, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x85a0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb643, .x_block =  75, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x85a6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  75, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85ac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  74, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85b2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  73, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85b8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  72, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85be: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  71, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85c4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  70, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85ca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  69, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85d0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  68, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x85d6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  68, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x85dc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  68, .y_block =  11, .plm_room_argument = 0x9d14,  };
    case 0x85e2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x85e4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  46, .y_block = 107, .plm_room_argument = 0x9d84,  };
    case 0x85ea: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block = 122, .plm_room_argument = 0x9d8b,  };
    case 0x85f0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  61, .y_block =  87, .plm_room_argument = 0x9d8e,  };
    case 0x85f6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  64, .y_block =  87, .plm_room_argument = 0x9d91,  };
    case 0x85fc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =   8, .plm_room_argument = 0x9d96,  };
    case 0x8602: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  33, .y_block =   8, .plm_room_argument = 0x9d99,  };
    case 0x8608: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  36, .y_block =  50, .plm_room_argument =   0x15,  };
    case 0x860e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  34, .y_block = 103, .plm_room_argument =   0x16,  };
    case 0x8614: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef3f, .x_block =  37, .y_block = 118, .plm_room_argument =   0x17,  };
    case 0x861a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc85a, .x_block =  62, .y_block =  70, .plm_room_argument =   0x28,  };
    case 0x8620: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  62, .y_block = 102, .plm_room_argument =   0x29,  };
    case 0x8626: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  62, .y_block =   6, .plm_room_argument =   0x2a,  };
    case 0x862c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block = 150, .plm_room_argument =   0x2b,  };
    case 0x8632: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8634: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xc2c,  };
    case 0x863a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc854, .x_block =  54, .y_block =   3, .plm_room_argument =  0xc2d,  };
    case 0x8640: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8642: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc87e, .x_block =   6, .y_block =  46, .plm_room_argument =   0x2e,  };
    case 0x8648: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x864a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  14, .plm_room_argument = 0x9e40,  };
    case 0x8650: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  11, .plm_room_argument = 0x9e49,  };
    case 0x8656: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =   6, .plm_room_argument =  0xc2f,  };
    case 0x865c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =   6, .y_block =  23, .plm_room_argument =   0x18,  };
    case 0x8662: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8664: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block = 100, .y_block =  55, .plm_room_argument = 0x8000,  };
    case 0x866a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block = 100, .y_block =  55, .plm_room_argument =    0x0,  };
    case 0x8670: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc85a, .x_block =  30, .y_block =   6, .plm_room_argument =   0x30,  };
    case 0x8676: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  61, .y_block =  24, .plm_room_argument =   0x19,  };
    case 0x867c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x867e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  43, .plm_room_argument = 0x9f05,  };
    case 0x8684: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  35, .plm_room_argument = 0x8000,  };
    case 0x868a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  36, .plm_room_argument = 0x8000,  };
    case 0x8690: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x8696: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x869c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x86a2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x86a8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  41, .plm_room_argument = 0x8000,  };
    case 0x86ae: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  42, .plm_room_argument = 0x8000,  };
    case 0x86b4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  43, .plm_room_argument = 0x9f08,  };
    case 0x86ba: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  88, .y_block =  33, .plm_room_argument = 0x8000,  };
    case 0x86c0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  87, .y_block =  33, .plm_room_argument = 0x9f0b,  };
    case 0x86c6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  88, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x86cc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  87, .y_block =  10, .plm_room_argument = 0x9f0b,  };
    case 0x86d2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  88, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x86d8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  87, .y_block =  38, .plm_room_argument = 0x9f0e,  };
    case 0x86de: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef23, .x_block =  69, .y_block =  41, .plm_room_argument =   0x1a,  };
    case 0x86e4: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x86e6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  43, .plm_room_argument = 0x9f05,  };
    case 0x86ec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  35, .plm_room_argument = 0x8000,  };
    case 0x86f2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  36, .plm_room_argument = 0x8000,  };
    case 0x86f8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x86fe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8704: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x870a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x8710: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  41, .plm_room_argument = 0x8000,  };
    case 0x8716: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  42, .plm_room_argument = 0x8000,  };
    case 0x871c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  43, .plm_room_argument = 0x9f08,  };
    case 0x8722: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  88, .y_block =  33, .plm_room_argument = 0x8000,  };
    case 0x8728: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  87, .y_block =  33, .plm_room_argument = 0x9f0b,  };
    case 0x872e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  88, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8734: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  87, .y_block =  10, .plm_room_argument = 0x9f0b,  };
    case 0x873a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  88, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8740: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  87, .y_block =  38, .plm_room_argument = 0x9f0e,  };
    case 0x8746: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  38, .plm_room_argument =  0xc31,  };
    case 0x874c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =  40, .y_block =  42, .plm_room_argument =   0x1b,  };
    case 0x8752: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8754: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  11, .plm_room_argument = 0x9f5f,  };
    case 0x875a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8760: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8766: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x876c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8772: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8778: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x877e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  11, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8784: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =   6, .plm_room_argument =   0x32,  };
    case 0x878a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x878c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  39, .y_block =  11, .plm_room_argument = 0x9fb7,  };
    case 0x8792: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  39, .y_block =  38, .plm_room_argument = 0x9fb7,  };
    case 0x8798: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  46, .y_block =  41, .plm_room_argument =   0x1c,  };
    case 0x879e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7f, .x_block =  28, .y_block =  34, .plm_room_argument =   0x1d,  };
    case 0x87a4: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87a6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  94, .y_block =   6, .plm_room_argument =   0x33,  };
    case 0x87ac: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87ae: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87b0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  11, .plm_room_argument = 0xa04a,  };
    case 0x87b6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x87bc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x87c2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =   5, .y_block =   9, .plm_room_argument =   0x1e,  };
    case 0x87c8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block =   6, .plm_room_argument =   0x34,  };
    case 0x87ce: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87d0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =   7, .y_block =   9, .plm_room_argument =   0x1f,  };
    case 0x87d6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87d8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   4, .y_block =  10, .plm_room_argument =   0x20,  };
    case 0x87de: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87e0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block =   6, .plm_room_argument =   0x35,  };
    case 0x87e6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x87e8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x87ee: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x87f4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  11, .plm_room_argument = 0xa104,  };
    case 0x87fa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =   4, .y_block =   9, .plm_room_argument =   0x21,  };
    case 0x8800: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8802: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef2f, .x_block =   4, .y_block =   7, .plm_room_argument =   0x22,  };
    case 0x8808: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x880a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  17, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0x8810: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  17, .y_block =   4, .plm_room_argument =    0x2,  };
    case 0x8816: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument =  0xc36,  };
    case 0x881c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =  22, .plm_room_argument =  0xc37,  };
    case 0x8822: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8824: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =  11, .y_block =   9, .plm_room_argument =   0x23,  };
    case 0x882a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x882c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x0,  };
    case 0x8832: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8834: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8836: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   7, .y_block =   9, .plm_room_argument =   0x24,  };
    case 0x883c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =   5, .y_block =  12, .plm_room_argument =   0x25,  };
    case 0x8842: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8844: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x1,  };
    case 0x884a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x884c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x2,  };
    case 0x8852: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8854: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   9, .y_block = 106, .plm_room_argument = 0xa28e,  };
    case 0x885a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block = 106, .plm_room_argument = 0x8000,  };
    case 0x8860: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block = 150, .plm_room_argument =   0x38,  };
    case 0x8866: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc860, .x_block =   1, .y_block = 102, .plm_room_argument =   0x39,  };
    case 0x886c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x886e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =   6, .plm_room_argument =   0x3a,  };
    case 0x8874: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8876: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef63, .x_block =   5, .y_block =   7, .plm_room_argument =   0x26,  };
    case 0x887c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x887e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8880: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =  94, .plm_room_argument = 0xa36f,  };
    case 0x8886: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  94, .plm_room_argument = 0x8000,  };
    case 0x888c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =  55, .plm_room_argument = 0xa374,  };
    case 0x8892: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block =  55, .plm_room_argument = 0xa379,  };
    case 0x8898: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb70b, .x_block =   6, .y_block =  44, .plm_room_argument = 0x8000,  };
    case 0x889e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  38, .y_block =  53, .plm_room_argument = 0x8000,  };
    case 0x88a4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  38, .y_block =  53, .plm_room_argument =    0xa,  };
    case 0x88aa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block =  54, .plm_room_argument =   0x3b,  };
    case 0x88b0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc860, .x_block =   1, .y_block =  86, .plm_room_argument =   0x3c,  };
    case 0x88b6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block = 118, .plm_room_argument =   0x3d,  };
    case 0x88bc: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x88be: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  14, .plm_room_argument = 0xa3a9,  };
    case 0x88c4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x88ca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =   4, .y_block =  19, .plm_room_argument =   0x27,  };
    case 0x88d0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =   6, .plm_room_argument =  0xc3e,  };
    case 0x88d6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x88d8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0x88de: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x88e4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x88ea: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x88f0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x88f6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x88fc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8902: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8908: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  12, .plm_room_argument = 0xa3da,  };
    case 0x890e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef37, .x_block =  20, .y_block =   9, .plm_room_argument =   0x28,  };
    case 0x8914: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   2, .y_block =   8, .plm_room_argument =   0x29,  };
    case 0x891a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x891c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x891e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =  17, .plm_room_argument = 0xa439,  };
    case 0x8924: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  17, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x892a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  18, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x8930: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  19, .y_block =  17, .plm_room_argument = 0x8000,  };
    case 0x8936: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =  20, .plm_room_argument = 0xa43e,  };
    case 0x893c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  17, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0x8942: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  18, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0x8948: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  19, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0x894e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  17, .plm_room_argument = 0xa439,  };
    case 0x8954: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  20, .plm_room_argument = 0xa43e,  };
    case 0x895a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   2, .y_block =  17, .plm_room_argument = 0xa439,  };
    case 0x8960: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   2, .y_block =  20, .plm_room_argument = 0xa43e,  };
    case 0x8966: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  30, .y_block =   6, .plm_room_argument =   0x3f,  };
    case 0x896c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x896e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef53, .x_block =  11, .y_block =   9, .plm_room_argument =   0x2a,  };
    case 0x8974: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8976: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   2, .y_block =  11, .plm_room_argument = 0xa4a2,  };
    case 0x897c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   2, .y_block =  25, .plm_room_argument = 0xa4a9,  };
    case 0x8982: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  25, .plm_room_argument = 0xa4ae,  };
    case 0x8988: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  21, .y_block =  25, .plm_room_argument = 0xa4a9,  };
    case 0x898e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument =   0x40,  };
    case 0x8994: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8996: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  14, .y_block =   6, .plm_room_argument =  0xc41,  };
    case 0x899c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7f, .x_block =   5, .y_block =   4, .plm_room_argument =   0x2b,  };
    case 0x89a2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x89a4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  23, .y_block =  11, .plm_room_argument = 0xa50f,  };
    case 0x89aa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  23, .y_block =  14, .plm_room_argument = 0xa514,  };
    case 0x89b0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0x89b6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x89bc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x89c2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x89c8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x89ce: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x89d4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x89da: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  11, .y_block =  11, .plm_room_argument = 0xa519,  };
    case 0x89e0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  39, .y_block =  12, .plm_room_argument = 0xa51c,  };
    case 0x89e6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  46, .y_block =  12, .plm_room_argument = 0xa51c,  };
    case 0x89ec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =  46, .y_block =   8, .plm_room_argument =   0x2c,  };
    case 0x89f2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x89f4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  94, .y_block =   6, .plm_room_argument =  0xc42,  };
    case 0x89fa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xc43,  };
    case 0x8a00: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a02: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   3, .y_block =  18, .plm_room_argument = 0xa59c,  };
    case 0x8a08: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   4, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8a0e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8a14: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  14, .y_block =   6, .plm_room_argument =   0x44,  };
    case 0x8a1a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb5a, .x_block =  30, .y_block =  22, .plm_room_argument =   0x45,  };
    case 0x8a20: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb60, .x_block =  30, .y_block =  25, .plm_room_argument =   0x45,  };
    case 0x8a26: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb56, .x_block =  30, .y_block =  23, .plm_room_argument =   0x45,  };
    case 0x8a2c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a2e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =  22, .plm_room_argument =   0x46,  };
    case 0x8a34: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument =   0x47,  };
    case 0x8a3a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a3c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a3e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   4, .y_block =  10, .plm_room_argument =   0x2d,  };
    case 0x8a44: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a46: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6eb, .x_block =   9, .y_block =  10, .plm_room_argument =   0x2e,  };
    case 0x8a4c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   7, .y_block =  10, .plm_room_argument =   0x2f,  };
    case 0x8a52: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a54: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument = 0x9448,  };
    case 0x8a5a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8a5c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  12, .plm_room_argument = 0xa6d6,  };
    case 0x8a62: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8a68: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =   9, .plm_room_argument = 0xa6d9,  };
    case 0x8a6e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  16, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8a74: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  16, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x8a7a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  18, .y_block =   9, .plm_room_argument = 0xa6dc,  };
    case 0x8a80: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8a86: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x8a8c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x8a92: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  19, .y_block =  11, .plm_room_argument = 0xa6df,  };
    case 0x8a98: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  20, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8a9e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8aa4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0x8aaa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8ab0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x8ab6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x8abc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x8ac2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0x8ac8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8aca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef5b, .x_block =   7, .y_block =   9, .plm_room_argument =   0x30,  };
    case 0x8ad0: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8ad2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x3,  };
    case 0x8ad8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8ada: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x4,  };
    case 0x8ae0: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8ae2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8ae4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =  34, .y_block =  28, .plm_room_argument =   0x31,  };
    case 0x8aea: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  46, .y_block =  22, .plm_room_argument =   0x49,  };
    case 0x8af0: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8af2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  46, .y_block =   6, .plm_room_argument =   0x4a,  };
    case 0x8af8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8afa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb70b, .x_block =   6, .y_block =  44, .plm_room_argument = 0x8000,  };
    case 0x8b00: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block =  54, .plm_room_argument =   0x4b,  };
    case 0x8b06: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc860, .x_block =   1, .y_block =  70, .plm_room_argument =   0x4c,  };
    case 0x8b0c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =  86, .plm_room_argument =   0x4d,  };
    case 0x8b12: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b14: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  55, .y_block =  45, .plm_room_argument = 0xa860,  };
    case 0x8b1a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  56, .y_block =  45, .plm_room_argument = 0x8000,  };
    case 0x8b20: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b22: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b24: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef43, .x_block =  12, .y_block =   7, .plm_room_argument =   0x32,  };
    case 0x8b2a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b2c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  23, .plm_room_argument = 0xa8ec,  };
    case 0x8b32: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block =  23, .plm_room_argument = 0xa8ef,  };
    case 0x8b38: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  17, .y_block =  23, .plm_room_argument = 0xa8f2,  };
    case 0x8b3e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  19, .y_block =  23, .plm_room_argument = 0xa8f5,  };
    case 0x8b44: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b46: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =   1, .y_block =   8, .plm_room_argument =   0x33,  };
    case 0x8b4c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b4e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block = 158, .y_block =  40, .plm_room_argument = 0xa980,  };
    case 0x8b54: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 158, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x8b5a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 158, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8b60: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 158, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x8b66: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 158, .y_block =  36, .plm_room_argument = 0x8000,  };
    case 0x8b6c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block = 190, .y_block =  41, .plm_room_argument = 0xa987,  };
    case 0x8b72: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 190, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x8b78: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 190, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x8b7e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block = 194, .y_block =  41, .plm_room_argument = 0xa98a,  };
    case 0x8b84: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 194, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x8b8a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 194, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x8b90: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block = 194, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8b96: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc87e, .x_block = 198, .y_block =  45, .plm_room_argument =   0x4e,  };
    case 0x8b9c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8b9e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc854, .x_block =  54, .y_block =   2, .plm_room_argument =  0x44f,  };
    case 0x8ba4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block = 125, .y_block =   6, .plm_room_argument =   0x34,  };
    case 0x8baa: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8bac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef47, .x_block =   3, .y_block =  10, .plm_room_argument =   0x35,  };
    case 0x8bb2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8bb4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =   6, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x8bba: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =   6, .y_block =   5, .plm_room_argument =    0xa,  };
    case 0x8bc0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  13, .y_block =   9, .plm_room_argument =   0x36,  };
    case 0x8bc6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8bc8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =  12, .plm_room_argument = 0xaa75,  };
    case 0x8bce: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =   5, .plm_room_argument = 0xaa70,  };
    case 0x8bd4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  28, .plm_room_argument = 0xaa7c,  };
    case 0x8bda: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  11, .y_block =  18, .plm_room_argument = 0xaa7f,  };
    case 0x8be0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =   6, .plm_room_argument =  0xc50,  };
    case 0x8be6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   9, .y_block =   6, .plm_room_argument =   0x37,  };
    case 0x8bec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =  23, .y_block =   8, .plm_room_argument =   0x38,  };
    case 0x8bf2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8bf4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =   6, .plm_room_argument =   0x51,  };
    case 0x8bfa: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8bfc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x0,  };
    case 0x8c02: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c04: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =   7, .y_block =   8, .plm_room_argument =   0x39,  };
    case 0x8c0a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c0c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  54, .plm_room_argument =   0x52,  };
    case 0x8c12: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c14: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  60, .y_block =   9, .plm_room_argument =   0x3a,  };
    case 0x8c1a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c1c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  42, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x8c22: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  42, .y_block =   5, .plm_room_argument =    0x8,  };
    case 0x8c28: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c2a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  67, .y_block =   9, .plm_room_argument =   0x3b,  };
    case 0x8c30: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c32: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c34: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c36: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef6b, .x_block =   4, .y_block =  39, .plm_room_argument =   0x3c,  };
    case 0x8c3c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c3e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7b, .x_block =   2, .y_block =   7, .plm_room_argument =   0x3d,  };
    case 0x8c44: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =   7, .y_block =  11, .plm_room_argument =   0x3e,  };
    case 0x8c4a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c4c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =   5, .plm_room_argument = 0xacb0,  };
    case 0x8c52: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  20, .y_block =  10, .plm_room_argument =   0x3f,  };
    case 0x8c58: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c5a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =   1, .y_block =   6, .plm_room_argument =   0x53,  };
    case 0x8c60: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  30, .y_block =   6, .plm_room_argument =   0x54,  };
    case 0x8c66: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  20, .y_block =  60, .plm_room_argument =   0x40,  };
    case 0x8c6c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c6e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb8ac, .x_block =   0, .y_block =   0, .plm_room_argument = 0x8000,  };
    case 0x8c74: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block = 188, .y_block =  19, .plm_room_argument =   0x41,  };
    case 0x8c7a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block = 190, .y_block =  22, .plm_room_argument =   0x55,  };
    case 0x8c80: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c82: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef4b, .x_block =  11, .y_block =   6, .plm_room_argument =   0x42,  };
    case 0x8c88: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8c8a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block =   8, .plm_room_argument = 0xada7,  };
    case 0x8c90: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =   8, .plm_room_argument = 0xadaa,  };
    case 0x8c96: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  77, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8c9c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  77, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8ca2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  77, .y_block =  12, .plm_room_argument = 0xadaa,  };
    case 0x8ca8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  22, .plm_room_argument =   0x56,  };
    case 0x8cae: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8cb0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  26, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x8cb6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  26, .y_block =   5, .plm_room_argument =    0x0,  };
    case 0x8cbc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  31, .y_block =   9, .plm_room_argument =   0x43,  };
    case 0x8cc2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  62, .y_block =   6, .plm_room_argument =   0x57,  };
    case 0x8cc8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8cca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef4f, .x_block =  11, .y_block =   6, .plm_room_argument =   0x44,  };
    case 0x8cd0: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8cd2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8cd4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block =  41, .plm_room_argument = 0xae66,  };
    case 0x8cda: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  41, .plm_room_argument = 0xae6b,  };
    case 0x8ce0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  25, .y_block =  36, .plm_room_argument = 0x8000,  };
    case 0x8ce6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  25, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x8cec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  25, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8cf2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  25, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x8cf8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  25, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x8cfe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  25, .y_block =  41, .plm_room_argument = 0xae6e,  };
    case 0x8d04: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  38, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x8d0a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  38, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x8d10: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  38, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x8d16: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  38, .y_block =  41, .plm_room_argument = 0xae71,  };
    case 0x8d1c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d1e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  23, .plm_room_argument = 0xaea9,  };
    case 0x8d24: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  17, .y_block =  23, .plm_room_argument = 0xaeac,  };
    case 0x8d2a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  21, .plm_room_argument = 0x8000,  };
    case 0x8d30: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  22, .plm_room_argument = 0x8000,  };
    case 0x8d36: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  23, .plm_room_argument = 0x8000,  };
    case 0x8d3c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  24, .plm_room_argument = 0xaeb1,  };
    case 0x8d42: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =   7, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0x8d48: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =   7, .y_block =  20, .plm_room_argument =    0x0,  };
    case 0x8d4e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc860, .x_block =  17, .y_block =  38, .plm_room_argument =   0x58,  };
    case 0x8d54: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d56: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d58: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   2, .y_block =  11, .plm_room_argument = 0xaf0f,  };
    case 0x8d5e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   3, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8d64: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   4, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8d6a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  11, .y_block =  11, .plm_room_argument = 0xaf0f,  };
    case 0x8d70: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  12, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8d76: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  13, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x8d7c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d7e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d80: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  11, .plm_room_argument = 0xaf6f,  };
    case 0x8d86: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d88: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =   6, .y_block =  21, .plm_room_argument = 0x8000,  };
    case 0x8d8e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =   6, .y_block =  21, .plm_room_argument =    0x0,  };
    case 0x8d94: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d96: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d98: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d9a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8d9c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   7, .y_block =  10, .plm_room_argument =   0x45,  };
    case 0x8da2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8da4: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8da6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   9, .y_block =  12, .plm_room_argument = 0xb0a7,  };
    case 0x8dac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8db2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   9, .y_block =  16, .plm_room_argument = 0xb0ac,  };
    case 0x8db8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8dbe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   6, .y_block =  19, .plm_room_argument = 0xb0b1,  };
    case 0x8dc4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  19, .plm_room_argument = 0x8000,  };
    case 0x8dca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  19, .plm_room_argument = 0x8000,  };
    case 0x8dd0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  19, .plm_room_argument = 0x8000,  };
    case 0x8dd6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8dd8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6d3, .x_block =   5, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0x8dde: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8de0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x1,  };
    case 0x8de6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8de8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8dea: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8dec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x2,  };
    case 0x8df2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8df4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x3,  };
    case 0x8dfa: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8dfc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x4,  };
    case 0x8e02: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8e04: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  12, .y_block =  30, .plm_room_argument = 0xb224,  };
    case 0x8e0a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  12, .y_block =  35, .plm_room_argument = 0xb22d,  };
    case 0x8e10: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8e12: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  71, .y_block =   8, .plm_room_argument = 0xb27d,  };
    case 0x8e18: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  72, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8e1e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  71, .y_block =  35, .plm_room_argument = 0xb27d,  };
    case 0x8e24: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  72, .y_block =  35, .plm_room_argument = 0x8000,  };
    case 0x8e2a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  71, .y_block =  41, .plm_room_argument = 0xb280,  };
    case 0x8e30: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  72, .y_block =  41, .plm_room_argument = 0x8000,  };
    case 0x8e36: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb70b, .x_block =  70, .y_block =  42, .plm_room_argument = 0x8000,  };
    case 0x8e3c: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8e3e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  12, .plm_room_argument = 0xb2d1,  };
    case 0x8e44: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e4a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e50: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e56: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e5c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e62: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e68: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  11, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0x8e6e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  13, .y_block =   8, .plm_room_argument =   0x46,  };
    case 0x8e74: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef87, .x_block =  21, .y_block =   8, .plm_room_argument =   0x47,  };
    case 0x8e7a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =  22, .plm_room_argument =  0x859,  };
    case 0x8e80: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8e82: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  52, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x8e88: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  52, .y_block =   5, .plm_room_argument =    0x8,  };
    case 0x8e8e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8e90: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   8, .y_block =  10, .plm_room_argument =   0x48,  };
    case 0x8e96: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8e98: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  14, .y_block =   6, .plm_room_argument =   0x5a,  };
    case 0x8e9e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument =   0x5b,  };
    case 0x8ea4: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8ea6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb4c, .x_block =   1, .y_block =   6, .plm_room_argument =   0x5c,  };
    case 0x8eac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb52, .x_block =   1, .y_block =   9, .plm_room_argument =   0x5c,  };
    case 0x8eb2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb48, .x_block =   1, .y_block =   7, .plm_room_argument =   0x5c,  };
    case 0x8eb8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8eba: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  33, .plm_room_argument = 0xb3d9,  };
    case 0x8ec0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  33, .plm_room_argument = 0x8000,  };
    case 0x8ec6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  27, .plm_room_argument = 0xb3dc,  };
    case 0x8ecc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  27, .plm_room_argument = 0x8000,  };
    case 0x8ed2: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8ed6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  48, .y_block =  22, .plm_room_argument = 0xb445,  };
    case 0x8edc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  50, .y_block =  22, .plm_room_argument = 0xb448,  };
    case 0x8ee2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  45, .y_block =  22, .plm_room_argument = 0xb44b,  };
    case 0x8ee8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  43, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0x8eee: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  43, .y_block =  21, .plm_room_argument = 0x8000,  };
    case 0x8ef4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  43, .y_block =  22, .plm_room_argument = 0x8000,  };
    case 0x8efa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  43, .y_block =  23, .plm_room_argument = 0xb44e,  };
    case 0x8f00: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  56, .y_block =  54, .plm_room_argument = 0x8000,  };
    case 0x8f06: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  56, .y_block =  55, .plm_room_argument = 0x8000,  };
    case 0x8f0c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  56, .y_block =  56, .plm_room_argument = 0x8000,  };
    case 0x8f12: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  56, .y_block =  57, .plm_room_argument = 0xb451,  };
    case 0x8f18: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  61, .y_block =  52, .plm_room_argument = 0x8000,  };
    case 0x8f1e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  60, .y_block =  52, .plm_room_argument = 0x8000,  };
    case 0x8f24: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  59, .y_block =  52, .plm_room_argument = 0xb454,  };
    case 0x8f2a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  54, .plm_room_argument =  0xc5d,  };
    case 0x8f30: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  39, .y_block =  27, .plm_room_argument =   0x49,  };
    case 0x8f36: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8f38: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8f3a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8f3c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   3, .y_block =  16, .plm_room_argument = 0xb4e0,  };
    case 0x8f42: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   4, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f48: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f4e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f54: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f5a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f60: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f66: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f6c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  11, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f72: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  12, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0x8f78: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8f7a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8f7c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  12, .y_block =   9, .plm_room_argument = 0xb547,  };
    case 0x8f82: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  12, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x8f88: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  12, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x8f8e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  12, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x8f94: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   3, .y_block =  18, .plm_room_argument = 0xb54e,  };
    case 0x8f9a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   4, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fa0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fa6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fac: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fb2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fb8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fbe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0x8fc4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  47, .y_block =   3, .plm_room_argument = 0xb555,  };
    case 0x8fca: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  43, .y_block =   7, .plm_room_argument =   0x4a,  };
    case 0x8fd0: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8fd2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =  12, .y_block =   8, .plm_room_argument =   0x4b,  };
    case 0x8fd8: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x8fda: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  17, .y_block =  72, .plm_room_argument = 0xb5c3,  };
    case 0x8fe0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  70, .plm_room_argument = 0x8000,  };
    case 0x8fe6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   8, .y_block =  70, .plm_room_argument = 0x8000,  };
    case 0x8fec: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  71, .plm_room_argument = 0xb5c8,  };
    case 0x8ff2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  72, .plm_room_argument = 0xb5c3,  };
    case 0x8ff8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  36, .y_block =  72, .plm_room_argument = 0xb5c8,  };
    case 0x8ffe: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   6, .y_block =  14, .plm_room_argument = 0xb5cd,  };
    case 0x9004: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x900a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x9010: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0x9016: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   6, .y_block =  11, .plm_room_argument = 0xb5d2,  };
    case 0x901c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x9022: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x9028: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x902e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc866, .x_block =  38, .y_block =  77, .plm_room_argument =   0x5e,  };
    case 0x9034: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x9036: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  23, .y_block =  13, .plm_room_argument = 0xb612,  };
    case 0x903c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0x9042: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  21, .y_block =   8, .plm_room_argument = 0xb615,  };
    case 0x9048: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  22, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x904e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x9054: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x905a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x9060: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  26, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x9066: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  79, .y_block =   9, .plm_room_argument = 0xb61a,  };
    case 0x906c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  81, .y_block =   9, .plm_room_argument = 0xb622,  };
    case 0x9072: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  11, .plm_room_argument = 0xb61d,  };
    case 0x9078: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  60, .y_block =   9, .plm_room_argument = 0xb622,  };
    case 0x907e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  63, .y_block =   9, .plm_room_argument = 0xb61a,  };
    case 0x9084: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  20, .y_block =   7, .plm_room_argument = 0xb625,  };
    case 0x908a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x9090: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x9096: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  20, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0x909c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   9, .y_block =   9, .plm_room_argument = 0xb628,  };
    case 0x90a2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   9, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x90a8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   9, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x90ae: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   9, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x90b4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =   9, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0x90ba: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc878, .x_block =  17, .y_block =  38, .plm_room_argument =   0x5f,  };
    case 0x90c0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =   7, .y_block =   8, .plm_room_argument =   0x4c,  };
    case 0x90c6: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x90c8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xc60,  };
    case 0x90ce: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x90d0: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  11, .y_block =  42, .plm_room_argument = 0xb68d,  };
    case 0x90d6: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  41, .plm_room_argument = 0x8000,  };
    case 0x90dc: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0x90e2: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0x90e8: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0x90ee: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  37, .plm_room_argument = 0x8000,  };
    case 0x90f4: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  42, .plm_room_argument = 0xb690,  };
    case 0x90fa: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  20, .y_block =  42, .plm_room_argument = 0xb695,  };
    case 0x9100: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   8, .y_block =  41, .plm_room_argument =   0x4d,  };
    case 0x9106: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x9108: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7f, .x_block =  14, .y_block =  11, .plm_room_argument =   0x4e,  };
    case 0x910e: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x9110: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef73, .x_block =  11, .y_block =  40, .plm_room_argument =   0x4f,  };
    case 0x9116: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x9118: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  54, .plm_room_argument = 0x8000,  };
    case 0x911e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  55, .plm_room_argument = 0x8000,  };
    case 0x9124: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  56, .plm_room_argument = 0xb72d,  };
    case 0x912a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  45, .y_block =  57, .plm_room_argument = 0x8000,  };
    case 0x9130: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  44, .y_block =  57, .plm_room_argument = 0x8000,  };
    case 0x9136: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  43, .y_block =  57, .plm_room_argument = 0xb730,  };
    case 0x913c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0x9142: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0x9148: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0x914e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =   9, .plm_room_argument = 0xb737,  };
    case 0x9154: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  27, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x915a: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  26, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x9160: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  25, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x9166: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  24, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x916c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x9172: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  22, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x9178: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  21, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0x917e: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  20, .y_block =  11, .plm_room_argument = 0xb73c,  };
    case 0x9184: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =  42, .y_block =  81, .plm_room_argument =   0x50,  };
    case 0x918a: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0x918c: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x5,  };
    case 0x9192: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc215: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  45, .plm_room_argument = 0xc9ec,  };
    case 0xc21b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  65, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc221: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  65, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc227: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  65, .y_block =  40, .plm_room_argument = 0xc9f1,  };
    case 0xc22d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc22f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc231: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =   0x80,  };
    case 0xc237: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block = 110, .y_block =   6, .plm_room_argument =   0x81,  };
    case 0xc23d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xbb05, .x_block =   8, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0xc243: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc245: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc247: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  62, .y_block =  87, .plm_room_argument = 0xcb7a,  };
    case 0xc24d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  81, .y_block = 105, .plm_room_argument = 0xcb7d,  };
    case 0xc253: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  65, .y_block =  87, .plm_room_argument = 0xcb80,  };
    case 0xc259: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  78, .y_block = 105, .plm_room_argument = 0xcb83,  };
    case 0xc25f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  71, .y_block = 109, .plm_room_argument = 0xcb86,  };
    case 0xc265: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   2, .y_block =  89, .plm_room_argument =   0x80,  };
    case 0xc26b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =  65, .y_block = 102, .plm_room_argument =   0x82,  };
    case 0xc271: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  78, .y_block =  70, .plm_room_argument =   0x83,  };
    case 0xc277: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc87e, .x_block =  70, .y_block = 125, .plm_room_argument =   0x84,  };
    case 0xc27d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc27f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc281: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  16, .plm_room_argument = 0xcc24,  };
    case 0xc287: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0xc28d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc28f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc291: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  64, .y_block =  12, .plm_room_argument = 0xccc0,  };
    case 0xc297: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  70, .y_block =  12, .plm_room_argument = 0xccc5,  };
    case 0xc29d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb5a, .x_block =  78, .y_block =   6, .plm_room_argument =   0x85,  };
    case 0xc2a3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb60, .x_block =  78, .y_block =   9, .plm_room_argument =   0x85,  };
    case 0xc2a9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb56, .x_block =  78, .y_block =   7, .plm_room_argument =   0x85,  };
    case 0xc2af: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2b1: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2b3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =   0x86,  };
    case 0xc2b9: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2bb: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2bd: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2bf: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  47, .y_block =   7, .plm_room_argument = 0xce3d,  };
    case 0xc2c5: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2c7: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2c9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x0,  };
    case 0xc2cf: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2d1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  45, .plm_room_argument = 0xc9ec,  };
    case 0xc2d7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  65, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc2dd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  65, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc2e3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  65, .y_block =  40, .plm_room_argument = 0xc9f1,  };
    case 0xc2e9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7b, .x_block =  83, .y_block =  11, .plm_room_argument =   0x81,  };
    case 0xc2ef: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  60, .y_block =  38, .plm_room_argument =   0x82,  };
    case 0xc2f5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument = 0x9087,  };
    case 0xc2fb: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2fd: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc2ff: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xc88,  };
    case 0xc305: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block = 110, .y_block =   6, .plm_room_argument =  0xc89,  };
    case 0xc30b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc84e, .x_block =  70, .y_block =  14, .plm_room_argument =  0xc8a,  };
    case 0xc311: return (RoomPlmEntry){ .plm_header_ptr_ = 0xbb05, .x_block =   8, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0xc317: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc319: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  45, .y_block =   8, .plm_room_argument =   0x83,  };
    case 0xc31f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc321: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc323: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  16, .plm_room_argument = 0xcc24,  };
    case 0xc329: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  16, .plm_room_argument = 0x8000,  };
    case 0xc32f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =   6, .plm_room_argument =   0x8b,  };
    case 0xc335: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc337: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =   3, .y_block =   6, .plm_room_argument =   0x84,  };
    case 0xc33d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc33f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  64, .y_block =  12, .plm_room_argument = 0xccc0,  };
    case 0xc345: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  70, .y_block =  12, .plm_room_argument = 0xccc5,  };
    case 0xc34b: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc34d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6d3, .x_block =   5, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0xc353: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc355: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc357: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =   2, .y_block =   7, .plm_room_argument =   0x85,  };
    case 0xc35d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc35f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  47, .y_block =   7, .plm_room_argument = 0xce3d,  };
    case 0xc365: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =  56, .y_block =   9, .plm_room_argument =   0x86,  };
    case 0xc36b: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc36d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef5f, .x_block =   7, .y_block =   9, .plm_room_argument =   0x87,  };
    case 0xc373: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc375: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x0,  };
    case 0xc37b: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc37d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   3, .y_block =  20, .plm_room_argument = 0xcf4c,  };
    case 0xc383: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   4, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc389: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc38f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc395: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   9, .y_block =  20, .plm_room_argument = 0xcf4c,  };
    case 0xc39b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc3a1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  11, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc3a7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  12, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc3ad: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =  29, .plm_room_argument = 0xcf4f,  };
    case 0xc3b3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  29, .plm_room_argument = 0x8000,  };
    case 0xc3b9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  29, .plm_room_argument = 0x8000,  };
    case 0xc3bf: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  29, .plm_room_argument = 0x8000,  };
    case 0xc3c5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  29, .plm_room_argument = 0x8000,  };
    case 0xc3cb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  29, .plm_room_argument = 0x8000,  };
    case 0xc3d1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xd70c, .x_block =   2, .y_block =  21, .plm_room_argument =   0x80,  };
    case 0xc3d7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  38, .plm_room_argument =   0x8c,  };
    case 0xc3dd: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc3df: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc3e1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =   9, .plm_room_argument = 0xcfb5,  };
    case 0xc3e7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =  16, .plm_room_argument = 0xcfbc,  };
    case 0xc3ed: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =  22, .plm_room_argument = 0xcfc1,  };
    case 0xc3f3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  10, .y_block =   3, .plm_room_argument = 0x8000,  };
    case 0xc3f9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  10, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0xc3ff: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  10, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0xc405: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  10, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0xc40b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  10, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0xc411: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  10, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0xc417: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  10, .y_block =   9, .plm_room_argument = 0xcfc6,  };
    case 0xc41d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  22, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0xc423: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  22, .y_block =   5, .plm_room_argument =    0xa,  };
    case 0xc429: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc42b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  37, .y_block =  41, .plm_room_argument = 0xd012,  };
    case 0xc431: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  30, .y_block = 118, .plm_room_argument =   0x8d,  };
    case 0xc437: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  14, .y_block =  53, .plm_room_argument =   0x88,  };
    case 0xc43d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =  22, .y_block =  40, .plm_room_argument =   0x89,  };
    case 0xc443: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc445: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc44b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc451: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0xc457: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  41, .plm_room_argument = 0xd052,  };
    case 0xc45d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  48, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc463: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  48, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc469: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  48, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0xc46f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  48, .y_block =  41, .plm_room_argument = 0xd052,  };
    case 0xc475: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  62, .y_block =  38, .plm_room_argument =   0x8e,  };
    case 0xc47b: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc47d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =  31, .y_block =  10, .plm_room_argument =   0x8a,  };
    case 0xc483: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =  44, .y_block =  29, .plm_room_argument =   0x8b,  };
    case 0xc489: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc48b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc82a, .x_block =  14, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0xc491: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc836, .x_block =  14, .y_block =   7, .plm_room_argument =    0x8,  };
    case 0xc497: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc499: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc49b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block =   6, .plm_room_argument = 0xd135,  };
    case 0xc4a1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  30, .y_block =   6, .plm_room_argument = 0xd138,  };
    case 0xc4a7: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc4a9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  31, .plm_room_argument = 0xd16a,  };
    case 0xc4af: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =   4, .y_block =  38, .plm_room_argument =   0x8c,  };
    case 0xc4b5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  11, .y_block =  39, .plm_room_argument =   0x8d,  };
    case 0xc4bb: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc4bd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  32, .y_block =  22, .plm_room_argument = 0x8000,  };
    case 0xc4c3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  32, .y_block =  23, .plm_room_argument = 0x8000,  };
    case 0xc4c9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  32, .y_block =  24, .plm_room_argument = 0x8000,  };
    case 0xc4cf: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  32, .y_block =  25, .plm_room_argument = 0xd1a0,  };
    case 0xc4d5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =  22, .plm_room_argument = 0x8000,  };
    case 0xc4db: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =  23, .plm_room_argument = 0x8000,  };
    case 0xc4e1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  15, .y_block =  24, .plm_room_argument = 0x8000,  };
    case 0xc4e7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  15, .y_block =  25, .plm_room_argument = 0xd1a0,  };
    case 0xc4ed: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc4ef: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   7, .y_block =  45, .plm_room_argument = 0xd1d8,  };
    case 0xc4f5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  45, .plm_room_argument = 0x8000,  };
    case 0xc4fb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  30, .y_block =  54, .plm_room_argument =   0x8f,  };
    case 0xc501: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc503: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc509: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc50f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  31, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0xc515: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  31, .y_block =  41, .plm_room_argument = 0xd216,  };
    case 0xc51b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  29, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc521: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  29, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc527: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  29, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0xc52d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  29, .y_block =  41, .plm_room_argument = 0xd219,  };
    case 0xc533: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  44, .y_block =  40, .plm_room_argument =   0x8e,  };
    case 0xc539: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc53b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  14, .plm_room_argument = 0xd24d,  };
    case 0xc541: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   8, .y_block =  17, .plm_room_argument = 0xd24d,  };
    case 0xc547: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  22, .plm_room_argument =   0x90,  };
    case 0xc54d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc54f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc551: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc553: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xc91,  };
    case 0xc559: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef67, .x_block =  25, .y_block =  38, .plm_room_argument =   0x8f,  };
    case 0xc55f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc561: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc563: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb70b, .x_block =   6, .y_block =  44, .plm_room_argument = 0x8000,  };
    case 0xc569: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  70, .plm_room_argument =   0x92,  };
    case 0xc56f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc571: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  46, .y_block =  22, .plm_room_argument =   0x93,  };
    case 0xc577: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc87e, .x_block =   6, .y_block =  45, .plm_room_argument =   0x94,  };
    case 0xc57d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc57f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc581: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6d3, .x_block =  11, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0xc587: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc589: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x1,  };
    case 0xc58f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc591: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc593: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc595: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc597: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   3, .y_block =  20, .plm_room_argument = 0xd4bd,  };
    case 0xc59d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   4, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5a3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5a9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5af: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5b5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5bb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5c1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5c7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  11, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5cd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  12, .y_block =  20, .plm_room_argument = 0x8000,  };
    case 0xc5d3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc884, .x_block =   6, .y_block =   2, .plm_room_argument =   0x95,  };
    case 0xc5d9: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc5db: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc5dd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   6, .y_block =   4, .plm_room_argument =   0x90,  };
    case 0xc5e3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef7b, .x_block =  15, .y_block =   4, .plm_room_argument =   0x91,  };
    case 0xc5e9: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc5eb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =   3, .y_block =   7, .plm_room_argument =   0x92,  };
    case 0xc5f1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeee3, .x_block =  25, .y_block =  16, .plm_room_argument =   0x93,  };
    case 0xc5f7: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc5f9: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc5fb: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc5fd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =  38, .plm_room_argument =   0x96,  };
    case 0xc603: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedb, .x_block =  76, .y_block =   9, .plm_room_argument =   0x94,  };
    case 0xc609: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeedf, .x_block =  92, .y_block =   8, .plm_room_argument =   0x95,  };
    case 0xc60f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc611: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  14, .y_block =   6, .plm_room_argument =   0x97,  };
    case 0xc617: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc619: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc61b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   6, .y_block =  50, .plm_room_argument = 0xd67d,  };
    case 0xc621: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  50, .plm_room_argument = 0x8000,  };
    case 0xc627: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  50, .plm_room_argument = 0x8000,  };
    case 0xc62d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  50, .plm_room_argument = 0x8000,  };
    case 0xc633: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  13, .y_block =  12, .plm_room_argument = 0xd67d,  };
    case 0xc639: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0xc63f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0xc645: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0xc64b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0xc651: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0xc657: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0xc65d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0xc663: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  13, .y_block =   4, .plm_room_argument = 0x8000,  };
    case 0xc669: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  18, .y_block =  14, .plm_room_argument = 0xd68a,  };
    case 0xc66f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =  13, .plm_room_argument = 0x8000,  };
    case 0xc675: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =  12, .plm_room_argument = 0x8000,  };
    case 0xc67b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =  11, .plm_room_argument = 0x8000,  };
    case 0xc681: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =  10, .plm_room_argument = 0x8000,  };
    case 0xc687: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =   9, .plm_room_argument = 0x8000,  };
    case 0xc68d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =   8, .plm_room_argument = 0x8000,  };
    case 0xc693: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  18, .y_block =   7, .plm_room_argument = 0x8000,  };
    case 0xc699: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  21, .y_block =  43, .plm_room_argument = 0xd695,  };
    case 0xc69f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  22, .y_block =  43, .plm_room_argument = 0x8000,  };
    case 0xc6a5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  23, .y_block =  43, .plm_room_argument = 0x8000,  };
    case 0xc6ab: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc6ad: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =  34, .plm_room_argument = 0xd6c8,  };
    case 0xc6b3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  34, .plm_room_argument = 0x8000,  };
    case 0xc6b9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  34, .plm_room_argument = 0x8000,  };
    case 0xc6bf: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  34, .plm_room_argument = 0x8000,  };
    case 0xc6c5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  34, .plm_room_argument = 0x8000,  };
    case 0xc6cb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  18, .plm_room_argument = 0x8000,  };
    case 0xc6d1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   5, .y_block =  27, .plm_room_argument = 0xd6cb,  };
    case 0xc6d7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  27, .plm_room_argument = 0x8000,  };
    case 0xc6dd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  27, .plm_room_argument = 0x8000,  };
    case 0xc6e3: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc6e5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef57, .x_block =  24, .y_block =  22, .plm_room_argument =   0x96,  };
    case 0xc6eb: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc6ed: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc6ef: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block = 110, .y_block =   6, .plm_room_argument =   0x98,  };
    case 0xc6f5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block =  78, .y_block =  38, .plm_room_argument =   0x99,  };
    case 0xc6fb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc872, .x_block = 110, .y_block =  22, .plm_room_argument =   0x9a,  };
    case 0xc701: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc703: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x2,  };
    case 0xc709: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc70b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =   4, .y_block =  14, .plm_room_argument = 0xd7df,  };
    case 0xc711: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   5, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc717: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   6, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc71d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   7, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc723: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   8, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc729: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =   9, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc72f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  10, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc735: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb63b, .x_block =  11, .y_block =  14, .plm_room_argument = 0x8000,  };
    case 0xc73b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb4c, .x_block =   1, .y_block =  38, .plm_room_argument =   0x9b,  };
    case 0xc741: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb52, .x_block =   1, .y_block =  41, .plm_room_argument =   0x9b,  };
    case 0xc747: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb48, .x_block =   1, .y_block =  39, .plm_room_argument =   0x9b,  };
    case 0xc74d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef83, .x_block =  28, .y_block =   6, .plm_room_argument =   0x97,  };
    case 0xc753: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc755: return (RoomPlmEntry){ .plm_header_ptr_ = 0xeed7, .x_block =  50, .y_block =   5, .plm_room_argument =   0x98,  };
    case 0xc75b: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc75d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x3,  };
    case 0xc763: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc765: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6eb, .x_block =   8, .y_block =  10, .plm_room_argument =   0x99,  };
    case 0xc76b: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc76d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc76f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc771: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc773: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  16, .y_block =  41, .plm_room_argument = 0xd951,  };
    case 0xc779: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  11, .y_block =  41, .plm_room_argument = 0xd956,  };
    case 0xc77f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  40, .plm_room_argument = 0x8000,  };
    case 0xc785: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  39, .plm_room_argument = 0x8000,  };
    case 0xc78b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb647, .x_block =  11, .y_block =  38, .plm_room_argument = 0x8000,  };
    case 0xc791: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb703, .x_block =  14, .y_block =  41, .plm_room_argument = 0xd95b,  };
    case 0xc797: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument =   0x9c,  };
    case 0xc79d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc79f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0x49d,  };
    case 0xc7a5: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7a7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xef6f, .x_block =   4, .y_block =   8, .plm_room_argument =   0x9a,  };
    case 0xc7ad: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7af: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   8, .y_block =  10, .plm_room_argument =   0x9b,  };
    case 0xc7b5: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7b7: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7b9: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7bb: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =   6, .plm_room_argument =   0x9e,  };
    case 0xc7c1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument =   0x9f,  };
    case 0xc7c7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdf65, .x_block =   2, .y_block =  11, .plm_room_argument = 0x8802,  };
    case 0xc7cd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdf59, .x_block =   2, .y_block =  18, .plm_room_argument = 0x8804,  };
    case 0xc7d3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdf71, .x_block =  29, .y_block =  15, .plm_room_argument = 0x8806,  };
    case 0xc7d9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdf71, .x_block =  29, .y_block =  21, .plm_room_argument = 0x8808,  };
    case 0xc7df: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7e1: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb70b, .x_block =   6, .y_block =  44, .plm_room_argument = 0x8000,  };
    case 0xc7e7: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7e9: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =   0x12,  };
    case 0xc7ef: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xca0,  };
    case 0xc7f5: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc7f7: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =   0x14,  };
    case 0xc7fd: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  14, .y_block =  22, .plm_room_argument =  0xca1,  };
    case 0xc803: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc805: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =   0x16,  };
    case 0xc80b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  94, .y_block =   6, .plm_room_argument =  0xca2,  };
    case 0xc811: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc813: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =   0x18,  };
    case 0xc819: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc84e, .x_block =   6, .y_block =  30, .plm_room_argument =  0xca3,  };
    case 0xc81f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc821: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc823: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  30, .y_block =   6, .plm_room_argument = 0x90a4,  };
    case 0xc829: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =   6, .plm_room_argument =  0xca5,  };
    case 0xc82f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc831: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc842, .x_block =  62, .y_block =   6, .plm_room_argument = 0x90a6,  };
    case 0xc837: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc839: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc88a, .x_block =  14, .y_block =  22, .plm_room_argument =   0xa7,  };
    case 0xc83f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc841: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6eb, .x_block =   8, .y_block =  10, .plm_room_argument =   0x9c,  };
    case 0xc847: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb6df, .x_block =   6, .y_block =  10, .plm_room_argument =   0x9d,  };
    case 0xc84d: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc84f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xd6de, .x_block =   9, .y_block =   5, .plm_room_argument = 0x8000,  };
    case 0xc855: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc857: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb5a, .x_block =  62, .y_block =   6, .plm_room_argument =   0xa8,  };
    case 0xc85d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb60, .x_block =  62, .y_block =   9, .plm_room_argument =   0xa8,  };
    case 0xc863: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb56, .x_block =  62, .y_block =   7, .plm_room_argument =   0xa8,  };
    case 0xc869: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc86b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc890, .x_block =   1, .y_block =  38, .plm_room_argument =   0xa9,  };
    case 0xc871: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc873: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   5, .y_block =  11, .plm_room_argument =    0x0,  };
    case 0xc879: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc87b: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0x0,  };
    case 0xc881: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc8ca, .x_block =  31, .y_block =   6, .plm_room_argument = 0x8000,  };
    case 0xc887: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc889: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0x2,  };
    case 0xc88f: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc854, .x_block =   6, .y_block =   3, .plm_room_argument = 0x90aa,  };
    case 0xc895: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc897: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0x4,  };
    case 0xc89d: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  22, .plm_room_argument = 0x90ab,  };
    case 0xc8a3: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8a5: return (RoomPlmEntry){ .plm_header_ptr_ = 0xdb44, .x_block =   8, .y_block =   8, .plm_room_argument =    0x6,  };
    case 0xc8ab: return (RoomPlmEntry){ .plm_header_ptr_ = 0xc848, .x_block =   1, .y_block =  54, .plm_room_argument = 0x90ac,  };
    case 0xc8b1: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8b3: return (RoomPlmEntry){ .plm_header_ptr_ = 0xb76f, .x_block =   7, .y_block =  11, .plm_room_argument =    0x1,  };
    case 0xc8b9: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8bb: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8bd: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8bf: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8c1: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8c3: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xc8c5: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    case 0xe87f: return (RoomPlmEntry){ .plm_header_ptr_ = 0x0000, };
    default: Unreachable(); return (RoomPlmEntry){ 0 };
  }
}

static PlmScrollData kPlmScrollData_92b0[] = {
  [0] = { .dst_scroll = 19, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9389[] = {
  [0] = { .dst_scroll =  8, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_938c[] = {
  [0] = { .dst_scroll =  8, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_938f[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  6, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9396[] = {
  [0] = { .dst_scroll =  6, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9399[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_939c[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_939f[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_93a2[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_93a5[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  8, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_94c2[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_94c7[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_94fa[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9658[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_968c[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9744[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9747[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_974a[] = {
  [0] = { .dst_scroll = 23, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_974d[] = {
  [0] = { .dst_scroll = 23, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9750[] = {
  [0] = { .dst_scroll = 24, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9753[] = {
  [0] = { .dst_scroll = 24, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9756[] = {
  [0] = { .dst_scroll = 25, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9759[] = {
  [0] = { .dst_scroll = 25, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_97ab[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_97b0[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9801[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9966[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_99f3[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_99f6[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9b46[] = {
  [0] = { .dst_scroll = 28, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 29, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9b4b[] = {
  [0] = { .dst_scroll = 28, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 29, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 41, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9b52[] = {
  [0] = { .dst_scroll = 24, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 28, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 29, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll = 41, .scroll_type = kScroll_Red   , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9b98[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9bf9[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9c00[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9c32[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d11[] = {
  [0] = { .dst_scroll = 11, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d14[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 11, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d84[] = {
  [0] = { .dst_scroll = 32, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 37, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 38, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d8b[] = {
  [0] = { .dst_scroll = 36, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d8e[] = {
  [0] = { .dst_scroll = 29, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d91[] = {
  [0] = { .dst_scroll = 28, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 29, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d96[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9d99[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9e40[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9e49[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9f05[] = {
  [0] = { .dst_scroll = 18, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9f08[] = {
  [0] = { .dst_scroll = 18, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9f0b[] = {
  [0] = { .dst_scroll = 13, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9f0e[] = {
  [0] = { .dst_scroll = 13, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9f5f[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_9fb7[] = {
  [0] = { .dst_scroll =  5, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a04a[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  5, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a104[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a28e[] = {
  [0] = { .dst_scroll =  6, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  7, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a36f[] = {
  [0] = { .dst_scroll = 15, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 18, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a374[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  9, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a379[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a3a9[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a3da[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a439[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a43e[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a4a2[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a4a9[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a4ae[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a50f[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  5, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a514[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  5, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a519[] = {
  [0] = { .dst_scroll =  5, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a51c[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  5, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a59c[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a6d6[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a6d9[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a6dc[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a6df[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a860[] = {
  [0] = { .dst_scroll = 17, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 24, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a8ec[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a8ef[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a8f2[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a8f5[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a980[] = {
  [0] = { .dst_scroll = 25, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 37, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 38, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a987[] = {
  [0] = { .dst_scroll = 37, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_a98a[] = {
  [0] = { .dst_scroll = 37, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aa70[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aa75[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aa7c[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aa7f[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_acb0[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ada7[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_adaa[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ae66[] = {
  [0] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  7, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ae6b[] = {
  [0] = { .dst_scroll =  8, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ae6e[] = {
  [0] = { .dst_scroll =  8, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ae71[] = {
  [0] = { .dst_scroll =  7, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aea9[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aeac[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_aeb1[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_af0f[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_af6f[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b0a7[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b0ac[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b0b1[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b224[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll =  6, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll =  7, .scroll_type = kScroll_Green , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b22d[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll =  7, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll =  8, .scroll_type = kScroll_Blue  , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b27d[] = {
  [0] = { .dst_scroll = 12, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b280[] = {
  [0] = { .dst_scroll = 12, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b2d1[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [4] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b3d9[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b3dc[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b445[] = {
  [0] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b448[] = {
  [0] = { .dst_scroll =  6, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b44b[] = {
  [0] = { .dst_scroll =  7, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b44e[] = {
  [0] = { .dst_scroll =  7, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b451[] = {
  [0] = { .dst_scroll = 14, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b454[] = {
  [0] = { .dst_scroll = 14, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b4e0[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b547[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll =  6, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b54e[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b555[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b5c3[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 13, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b5c8[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 13, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b5cd[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b5d2[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b612[] = {
  [0] = { .dst_scroll =  7, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b615[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  7, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b61a[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b61d[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b622[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b625[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b628[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b68d[] = {
  [0] = { .dst_scroll =  9, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b690[] = {
  [0] = { .dst_scroll =  8, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  9, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b695[] = {
  [0] = { .dst_scroll =  8, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b72d[] = {
  [0] = { .dst_scroll = 11, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b730[] = {
  [0] = { .dst_scroll = 11, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 13, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 14, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b737[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_b73c[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_c9ec[] = {
  [0] = { .dst_scroll = 14, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 15, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_c9f1[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  5, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 11, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll = 16, .scroll_type = kScroll_Blue  , },
  [4] = { .dst_scroll = 17, .scroll_type = kScroll_Blue  , },
  [5] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cb7a[] = {
  [0] = { .dst_scroll = 33, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cb7d[] = {
  [0] = { .dst_scroll = 41, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cb80[] = {
  [0] = { .dst_scroll = 33, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cb83[] = {
  [0] = { .dst_scroll = 41, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cb86[] = {
  [0] = { .dst_scroll = 40, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 46, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cc24[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ccc0[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ccc5[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_ce3d[] = {
  [0] = { .dst_scroll =  3, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cf4c[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cf4f[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cfb5[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cfbc[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cfc1[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_cfc6[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d012[] = {
  [0] = { .dst_scroll =  7, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 10, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d052[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d135[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d138[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d16a[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d1a0[] = {
  [0] = { .dst_scroll =  5, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d1d8[] = {
  [0] = { .dst_scroll =  4, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d216[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d219[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d24d[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d4bd[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d67d[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll =  4, .scroll_type = kScroll_Green , },
  [3] = { .dst_scroll =  5, .scroll_type = kScroll_Red   , },
  [4] = { .dst_scroll =  6, .scroll_type = kScroll_Blue  , },
  [5] = { .dst_scroll =  7, .scroll_type = kScroll_Red   , },
  [6] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d68a[] = {
  [0] = { .dst_scroll =  2, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll =  3, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll =  4, .scroll_type = kScroll_Red   , },
  [3] = { .dst_scroll =  5, .scroll_type = kScroll_Blue  , },
  [4] = { .dst_scroll =  6, .scroll_type = kScroll_Red   , },
  [5] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d695[] = {
  [0] = { .dst_scroll =  5, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  7, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d6c8[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d6cb[] = {
  [0] = { .dst_scroll =  1, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d7df[] = {
  [0] = { .dst_scroll =  0, .scroll_type = kScroll_Green , },
  [1] = { .dst_scroll =  2, .scroll_type = kScroll_Green , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d951[] = {
  [0] = { .dst_scroll =  5, .scroll_type = kScroll_Red   , },
  [1] = { .dst_scroll = 11, .scroll_type = kScroll_Blue  , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d956[] = {
  [0] = { .dst_scroll =  5, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 11, .scroll_type = kScroll_Red   , },
  [2] = { .dst_scroll = 0x80,},
};

static PlmScrollData kPlmScrollData_d95b[] = {
  [0] = { .dst_scroll = 10, .scroll_type = kScroll_Blue  , },
  [1] = { .dst_scroll = 0x80,},
};

PlmScrollData* get_PlmScrollData(uint16 plm_scroll_data_ptr) {
  switch (plm_scroll_data_ptr) {
    case 0x92b0: return kPlmScrollData_92b0;
    case 0x9389: return kPlmScrollData_9389;
    case 0x938c: return kPlmScrollData_938c;
    case 0x938f: return kPlmScrollData_938f;
    case 0x9396: return kPlmScrollData_9396;
    case 0x9399: return kPlmScrollData_9399;
    case 0x939c: return kPlmScrollData_939c;
    case 0x939f: return kPlmScrollData_939f;
    case 0x93a2: return kPlmScrollData_93a2;
    case 0x93a5: return kPlmScrollData_93a5;
    case 0x94c2: return kPlmScrollData_94c2;
    case 0x94c7: return kPlmScrollData_94c7;
    case 0x94fa: return kPlmScrollData_94fa;
    case 0x9658: return kPlmScrollData_9658;
    case 0x968c: return kPlmScrollData_968c;
    case 0x9744: return kPlmScrollData_9744;
    case 0x9747: return kPlmScrollData_9747;
    case 0x974a: return kPlmScrollData_974a;
    case 0x974d: return kPlmScrollData_974d;
    case 0x9750: return kPlmScrollData_9750;
    case 0x9753: return kPlmScrollData_9753;
    case 0x9756: return kPlmScrollData_9756;
    case 0x9759: return kPlmScrollData_9759;
    case 0x97ab: return kPlmScrollData_97ab;
    case 0x97b0: return kPlmScrollData_97b0;
    case 0x9801: return kPlmScrollData_9801;
    case 0x9966: return kPlmScrollData_9966;
    case 0x99f3: return kPlmScrollData_99f3;
    case 0x99f6: return kPlmScrollData_99f6;
    case 0x9b46: return kPlmScrollData_9b46;
    case 0x9b4b: return kPlmScrollData_9b4b;
    case 0x9b52: return kPlmScrollData_9b52;
    case 0x9b98: return kPlmScrollData_9b98;
    case 0x9bf9: return kPlmScrollData_9bf9;
    case 0x9c00: return kPlmScrollData_9c00;
    case 0x9c32: return kPlmScrollData_9c32;
    case 0x9d11: return kPlmScrollData_9d11;
    case 0x9d14: return kPlmScrollData_9d14;
    case 0x9d84: return kPlmScrollData_9d84;
    case 0x9d8b: return kPlmScrollData_9d8b;
    case 0x9d8e: return kPlmScrollData_9d8e;
    case 0x9d91: return kPlmScrollData_9d91;
    case 0x9d96: return kPlmScrollData_9d96;
    case 0x9d99: return kPlmScrollData_9d99;
    case 0x9e40: return kPlmScrollData_9e40;
    case 0x9e49: return kPlmScrollData_9e49;
    case 0x9f05: return kPlmScrollData_9f05;
    case 0x9f08: return kPlmScrollData_9f08;
    case 0x9f0b: return kPlmScrollData_9f0b;
    case 0x9f0e: return kPlmScrollData_9f0e;
    case 0x9f5f: return kPlmScrollData_9f5f;
    case 0x9fb7: return kPlmScrollData_9fb7;
    case 0xa04a: return kPlmScrollData_a04a;
    case 0xa104: return kPlmScrollData_a104;
    case 0xa28e: return kPlmScrollData_a28e;
    case 0xa36f: return kPlmScrollData_a36f;
    case 0xa374: return kPlmScrollData_a374;
    case 0xa379: return kPlmScrollData_a379;
    case 0xa3a9: return kPlmScrollData_a3a9;
    case 0xa3da: return kPlmScrollData_a3da;
    case 0xa439: return kPlmScrollData_a439;
    case 0xa43e: return kPlmScrollData_a43e;
    case 0xa4a2: return kPlmScrollData_a4a2;
    case 0xa4a9: return kPlmScrollData_a4a9;
    case 0xa4ae: return kPlmScrollData_a4ae;
    case 0xa50f: return kPlmScrollData_a50f;
    case 0xa514: return kPlmScrollData_a514;
    case 0xa519: return kPlmScrollData_a519;
    case 0xa51c: return kPlmScrollData_a51c;
    case 0xa59c: return kPlmScrollData_a59c;
    case 0xa6d6: return kPlmScrollData_a6d6;
    case 0xa6d9: return kPlmScrollData_a6d9;
    case 0xa6dc: return kPlmScrollData_a6dc;
    case 0xa6df: return kPlmScrollData_a6df;
    case 0xa860: return kPlmScrollData_a860;
    case 0xa8ec: return kPlmScrollData_a8ec;
    case 0xa8ef: return kPlmScrollData_a8ef;
    case 0xa8f2: return kPlmScrollData_a8f2;
    case 0xa8f5: return kPlmScrollData_a8f5;
    case 0xa980: return kPlmScrollData_a980;
    case 0xa987: return kPlmScrollData_a987;
    case 0xa98a: return kPlmScrollData_a98a;
    case 0xaa70: return kPlmScrollData_aa70;
    case 0xaa75: return kPlmScrollData_aa75;
    case 0xaa7c: return kPlmScrollData_aa7c;
    case 0xaa7f: return kPlmScrollData_aa7f;
    case 0xacb0: return kPlmScrollData_acb0;
    case 0xada7: return kPlmScrollData_ada7;
    case 0xadaa: return kPlmScrollData_adaa;
    case 0xae66: return kPlmScrollData_ae66;
    case 0xae6b: return kPlmScrollData_ae6b;
    case 0xae6e: return kPlmScrollData_ae6e;
    case 0xae71: return kPlmScrollData_ae71;
    case 0xaea9: return kPlmScrollData_aea9;
    case 0xaeac: return kPlmScrollData_aeac;
    case 0xaeb1: return kPlmScrollData_aeb1;
    case 0xaf0f: return kPlmScrollData_af0f;
    case 0xaf6f: return kPlmScrollData_af6f;
    case 0xb0a7: return kPlmScrollData_b0a7;
    case 0xb0ac: return kPlmScrollData_b0ac;
    case 0xb0b1: return kPlmScrollData_b0b1;
    case 0xb224: return kPlmScrollData_b224;
    case 0xb22d: return kPlmScrollData_b22d;
    case 0xb27d: return kPlmScrollData_b27d;
    case 0xb280: return kPlmScrollData_b280;
    case 0xb2d1: return kPlmScrollData_b2d1;
    case 0xb3d9: return kPlmScrollData_b3d9;
    case 0xb3dc: return kPlmScrollData_b3dc;
    case 0xb445: return kPlmScrollData_b445;
    case 0xb448: return kPlmScrollData_b448;
    case 0xb44b: return kPlmScrollData_b44b;
    case 0xb44e: return kPlmScrollData_b44e;
    case 0xb451: return kPlmScrollData_b451;
    case 0xb454: return kPlmScrollData_b454;
    case 0xb4e0: return kPlmScrollData_b4e0;
    case 0xb547: return kPlmScrollData_b547;
    case 0xb54e: return kPlmScrollData_b54e;
    case 0xb555: return kPlmScrollData_b555;
    case 0xb5c3: return kPlmScrollData_b5c3;
    case 0xb5c8: return kPlmScrollData_b5c8;
    case 0xb5cd: return kPlmScrollData_b5cd;
    case 0xb5d2: return kPlmScrollData_b5d2;
    case 0xb612: return kPlmScrollData_b612;
    case 0xb615: return kPlmScrollData_b615;
    case 0xb61a: return kPlmScrollData_b61a;
    case 0xb61d: return kPlmScrollData_b61d;
    case 0xb622: return kPlmScrollData_b622;
    case 0xb625: return kPlmScrollData_b625;
    case 0xb628: return kPlmScrollData_b628;
    case 0xb68d: return kPlmScrollData_b68d;
    case 0xb690: return kPlmScrollData_b690;
    case 0xb695: return kPlmScrollData_b695;
    case 0xb72d: return kPlmScrollData_b72d;
    case 0xb730: return kPlmScrollData_b730;
    case 0xb737: return kPlmScrollData_b737;
    case 0xb73c: return kPlmScrollData_b73c;
    case 0xc9ec: return kPlmScrollData_c9ec;
    case 0xc9f1: return kPlmScrollData_c9f1;
    case 0xcb7a: return kPlmScrollData_cb7a;
    case 0xcb7d: return kPlmScrollData_cb7d;
    case 0xcb80: return kPlmScrollData_cb80;
    case 0xcb83: return kPlmScrollData_cb83;
    case 0xcb86: return kPlmScrollData_cb86;
    case 0xcc24: return kPlmScrollData_cc24;
    case 0xccc0: return kPlmScrollData_ccc0;
    case 0xccc5: return kPlmScrollData_ccc5;
    case 0xce3d: return kPlmScrollData_ce3d;
    case 0xcf4c: return kPlmScrollData_cf4c;
    case 0xcf4f: return kPlmScrollData_cf4f;
    case 0xcfb5: return kPlmScrollData_cfb5;
    case 0xcfbc: return kPlmScrollData_cfbc;
    case 0xcfc1: return kPlmScrollData_cfc1;
    case 0xcfc6: return kPlmScrollData_cfc6;
    case 0xd012: return kPlmScrollData_d012;
    case 0xd052: return kPlmScrollData_d052;
    case 0xd135: return kPlmScrollData_d135;
    case 0xd138: return kPlmScrollData_d138;
    case 0xd16a: return kPlmScrollData_d16a;
    case 0xd1a0: return kPlmScrollData_d1a0;
    case 0xd1d8: return kPlmScrollData_d1d8;
    case 0xd216: return kPlmScrollData_d216;
    case 0xd219: return kPlmScrollData_d219;
    case 0xd24d: return kPlmScrollData_d24d;
    case 0xd4bd: return kPlmScrollData_d4bd;
    case 0xd67d: return kPlmScrollData_d67d;
    case 0xd68a: return kPlmScrollData_d68a;
    case 0xd695: return kPlmScrollData_d695;
    case 0xd6c8: return kPlmScrollData_d6c8;
    case 0xd6cb: return kPlmScrollData_d6cb;
    case 0xd7df: return kPlmScrollData_d7df;
    case 0xd951: return kPlmScrollData_d951;
    case 0xd956: return kPlmScrollData_d956;
    case 0xd95b: return kPlmScrollData_d95b;
    default: Unreachable(); return (PlmScrollData*){ 0 };
  }
}

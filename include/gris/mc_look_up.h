// ========================================================================= //
// Authors: David Spitzenberg, Daniel Ströter, Jan Reichert                  //
// GRIS - Graphisch Interaktive Systeme                                      //
// Technische Universität Darmstadt                                          //
// Fraunhoferstrasse 5                                                       //
// D-64283 Darmstadt, Germany                                                //
//                                                                           //
// Creation Date: unknown                                                    //
// Changed: 25.05.2021                                                       //
// Changed: 16.05.2022                                                       //
// Changed: 02.05.2025                                                       //
// ========================================================================= //
#pragma once

#include <glm/glm.hpp>

namespace gris {
// Indexing of corners
//
//      ^ Y
//      |
//      4-------------------5
//     /|                  /|
//    / |                 / |
//   /  |                /  |
//  7-------------------6   |
//  |   |               |   |
//  |   |               |   |
//  |   |               |   |
//  |   |               |   |
//  |   0---------------|---1--> X
//  |  /                |  /
//  | /                 | /
//  |/                  |/
//  3-------------------2
// /
//  Z

enum Corners : int {
    CORNER_0 = 1 << 0,
    CORNER_1 = 1 << 1,
    CORNER_2 = 1 << 2,
    CORNER_3 = 1 << 3,
    CORNER_4 = 1 << 4,
    CORNER_5 = 1 << 5,
    CORNER_6 = 1 << 6,
    CORNER_7 = 1 << 7,
};

// Indexing of the edges
//
//      o--------4----------o
//     /|                  /|
//    7 |                 5 |
//   /  |                /  |
//  o--------6----------o   |
//  |   8               |   9
//  |   |               |   |
//  |   |               |   |
//  11  |               10  |
//  |   o--------0------|---o
//  |  /                |  /
//  | 3                 | 1
//  |/                  |/
//  o--------2----------o
//

enum Edges : int {
    EDGE_0 = 1 << 0,
    EDGE_1 = 1 << 1,
    EDGE_2 = 1 << 2,
    EDGE_3 = 1 << 3,
    EDGE_4 = 1 << 4,
    EDGE_5 = 1 << 5,
    EDGE_6 = 1 << 6,
    EDGE_7 = 1 << 7,
    EDGE_8 = 1 << 8,
    EDGE_9 = 1 << 9,
    EDGE_10 = 1 << 10,
    EDGE_11 = 1 << 11,
};

const glm::ivec3 triangle_table[256][5] = {
    {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_8, EDGE_3}, {EDGE_9, EDGE_8, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_3}, {EDGE_1, EDGE_2, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_2, EDGE_10}, {EDGE_0, EDGE_2, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_8, EDGE_3}, {EDGE_2, EDGE_10, EDGE_8}, {EDGE_10, EDGE_9, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_11, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_11, EDGE_2}, {EDGE_8, EDGE_11, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_9, EDGE_0}, {EDGE_2, EDGE_3, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_11, EDGE_2}, {EDGE_1, EDGE_9, EDGE_11}, {EDGE_9, EDGE_8, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_10, EDGE_1}, {EDGE_11, EDGE_10, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_10, EDGE_1}, {EDGE_0, EDGE_8, EDGE_10}, {EDGE_8, EDGE_11, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_9, EDGE_0}, {EDGE_3, EDGE_11, EDGE_9}, {EDGE_11, EDGE_10, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_8, EDGE_10}, {EDGE_10, EDGE_8, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_7, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_3, EDGE_0}, {EDGE_7, EDGE_3, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_9}, {EDGE_8, EDGE_4, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_1, EDGE_9}, {EDGE_4, EDGE_7, EDGE_1}, {EDGE_7, EDGE_3, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_10}, {EDGE_8, EDGE_4, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_4, EDGE_7}, {EDGE_3, EDGE_0, EDGE_4}, {EDGE_1, EDGE_2, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_2, EDGE_10}, {EDGE_9, EDGE_0, EDGE_2}, {EDGE_8, EDGE_4, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_10, EDGE_9}, {EDGE_2, EDGE_9, EDGE_7}, {EDGE_2, EDGE_7, EDGE_3}, {EDGE_7, EDGE_9, EDGE_4}, {-1, -1, -1}},
    {{EDGE_8, EDGE_4, EDGE_7}, {EDGE_3, EDGE_11, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_4, EDGE_7}, {EDGE_11, EDGE_2, EDGE_4}, {EDGE_2, EDGE_0, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_0, EDGE_1}, {EDGE_8, EDGE_4, EDGE_7}, {EDGE_2, EDGE_3, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_7, EDGE_11}, {EDGE_9, EDGE_4, EDGE_11}, {EDGE_9, EDGE_11, EDGE_2}, {EDGE_9, EDGE_2, EDGE_1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_10, EDGE_1}, {EDGE_3, EDGE_11, EDGE_10}, {EDGE_7, EDGE_8, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_11, EDGE_10}, {EDGE_1, EDGE_4, EDGE_11}, {EDGE_1, EDGE_0, EDGE_4}, {EDGE_7, EDGE_11, EDGE_4}, {-1, -1, -1}},
    {{EDGE_4, EDGE_7, EDGE_8}, {EDGE_9, EDGE_0, EDGE_11}, {EDGE_9, EDGE_11, EDGE_10}, {EDGE_11, EDGE_0, EDGE_3}, {-1, -1, -1}},
    {{EDGE_4, EDGE_7, EDGE_11}, {EDGE_4, EDGE_11, EDGE_9}, {EDGE_9, EDGE_11, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_4}, {EDGE_0, EDGE_8, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_5, EDGE_4}, {EDGE_1, EDGE_5, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_5, EDGE_4}, {EDGE_8, EDGE_3, EDGE_5}, {EDGE_3, EDGE_1, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_10}, {EDGE_9, EDGE_5, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_0, EDGE_8}, {EDGE_1, EDGE_2, EDGE_10}, {EDGE_4, EDGE_9, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_2, EDGE_10}, {EDGE_5, EDGE_4, EDGE_2}, {EDGE_4, EDGE_0, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_10, EDGE_5}, {EDGE_3, EDGE_2, EDGE_5}, {EDGE_3, EDGE_5, EDGE_4}, {EDGE_3, EDGE_4, EDGE_8}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_4}, {EDGE_2, EDGE_3, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_11, EDGE_2}, {EDGE_0, EDGE_8, EDGE_11}, {EDGE_4, EDGE_9, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_5, EDGE_4}, {EDGE_0, EDGE_1, EDGE_5}, {EDGE_2, EDGE_3, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_1, EDGE_5}, {EDGE_2, EDGE_5, EDGE_8}, {EDGE_2, EDGE_8, EDGE_11}, {EDGE_4, EDGE_8, EDGE_5}, {-1, -1, -1}},
    {{EDGE_10, EDGE_3, EDGE_11}, {EDGE_10, EDGE_1, EDGE_3}, {EDGE_9, EDGE_5, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_9, EDGE_5}, {EDGE_0, EDGE_8, EDGE_1}, {EDGE_8, EDGE_10, EDGE_1}, {EDGE_8, EDGE_11, EDGE_10}, {-1, -1, -1}},
    {{EDGE_5, EDGE_4, EDGE_0}, {EDGE_5, EDGE_0, EDGE_11}, {EDGE_5, EDGE_11, EDGE_10}, {EDGE_11, EDGE_0, EDGE_3}, {-1, -1, -1}},
    {{EDGE_5, EDGE_4, EDGE_8}, {EDGE_5, EDGE_8, EDGE_10}, {EDGE_10, EDGE_8, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_7, EDGE_8}, {EDGE_5, EDGE_7, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_3, EDGE_0}, {EDGE_9, EDGE_5, EDGE_3}, {EDGE_5, EDGE_7, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_7, EDGE_8}, {EDGE_0, EDGE_1, EDGE_7}, {EDGE_1, EDGE_5, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_5, EDGE_3}, {EDGE_3, EDGE_5, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_7, EDGE_8}, {EDGE_9, EDGE_5, EDGE_7}, {EDGE_10, EDGE_1, EDGE_2}, {-1, -1, -1}},
    {{EDGE_10, EDGE_1, EDGE_2}, {EDGE_9, EDGE_5, EDGE_0}, {EDGE_5, EDGE_3, EDGE_0}, {EDGE_5, EDGE_7, EDGE_3}, {-1, -1, -1}},
    {{EDGE_8, EDGE_0, EDGE_2}, {EDGE_8, EDGE_2, EDGE_5}, {EDGE_8, EDGE_5, EDGE_7}, {EDGE_10, EDGE_5, EDGE_2}, {-1, -1, -1}},
    {{EDGE_2, EDGE_10, EDGE_5}, {EDGE_2, EDGE_5, EDGE_3}, {EDGE_3, EDGE_5, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_7, EDGE_9, EDGE_5}, {EDGE_7, EDGE_8, EDGE_9}, {EDGE_3, EDGE_11, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_7}, {EDGE_9, EDGE_7, EDGE_2}, {EDGE_9, EDGE_2, EDGE_0}, {EDGE_2, EDGE_7, EDGE_11}, {-1, -1, -1}},
    {{EDGE_2, EDGE_3, EDGE_11}, {EDGE_0, EDGE_1, EDGE_8}, {EDGE_1, EDGE_7, EDGE_8}, {EDGE_1, EDGE_5, EDGE_7}, {-1, -1, -1}},
    {{EDGE_11, EDGE_2, EDGE_1}, {EDGE_11, EDGE_1, EDGE_7}, {EDGE_7, EDGE_1, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_8}, {EDGE_8, EDGE_5, EDGE_7}, {EDGE_10, EDGE_1, EDGE_3}, {EDGE_10, EDGE_3, EDGE_11}, {-1, -1, -1}},
    {{EDGE_5, EDGE_7, EDGE_0}, {EDGE_5, EDGE_0, EDGE_9}, {EDGE_7, EDGE_11, EDGE_0}, {EDGE_1, EDGE_0, EDGE_10}, {EDGE_11, EDGE_10, EDGE_0}},
    {{EDGE_11, EDGE_10, EDGE_0}, {EDGE_11, EDGE_0, EDGE_3}, {EDGE_10, EDGE_5, EDGE_0}, {EDGE_8, EDGE_0, EDGE_7}, {EDGE_5, EDGE_7, EDGE_0}},
    {{EDGE_11, EDGE_10, EDGE_5}, {EDGE_7, EDGE_11, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_6, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_3}, {EDGE_5, EDGE_10, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_0, EDGE_1}, {EDGE_5, EDGE_10, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_8, EDGE_3}, {EDGE_1, EDGE_9, EDGE_8}, {EDGE_5, EDGE_10, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_6, EDGE_5}, {EDGE_2, EDGE_6, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_6, EDGE_5}, {EDGE_1, EDGE_2, EDGE_6}, {EDGE_3, EDGE_0, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_6, EDGE_5}, {EDGE_9, EDGE_0, EDGE_6}, {EDGE_0, EDGE_2, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_9, EDGE_8}, {EDGE_5, EDGE_8, EDGE_2}, {EDGE_5, EDGE_2, EDGE_6}, {EDGE_3, EDGE_2, EDGE_8}, {-1, -1, -1}},
    {{EDGE_2, EDGE_3, EDGE_11}, {EDGE_10, EDGE_6, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_0, EDGE_8}, {EDGE_11, EDGE_2, EDGE_0}, {EDGE_10, EDGE_6, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_9}, {EDGE_2, EDGE_3, EDGE_11}, {EDGE_5, EDGE_10, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_10, EDGE_6}, {EDGE_1, EDGE_9, EDGE_2}, {EDGE_9, EDGE_11, EDGE_2}, {EDGE_9, EDGE_8, EDGE_11}, {-1, -1, -1}},
    {{EDGE_6, EDGE_3, EDGE_11}, {EDGE_6, EDGE_5, EDGE_3}, {EDGE_5, EDGE_1, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_11}, {EDGE_0, EDGE_11, EDGE_5}, {EDGE_0, EDGE_5, EDGE_1}, {EDGE_5, EDGE_11, EDGE_6}, {-1, -1, -1}},
    {{EDGE_3, EDGE_11, EDGE_6}, {EDGE_0, EDGE_3, EDGE_6}, {EDGE_0, EDGE_6, EDGE_5}, {EDGE_0, EDGE_5, EDGE_9}, {-1, -1, -1}},
    {{EDGE_6, EDGE_5, EDGE_9}, {EDGE_6, EDGE_9, EDGE_11}, {EDGE_11, EDGE_9, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_10, EDGE_6}, {EDGE_4, EDGE_7, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_3, EDGE_0}, {EDGE_4, EDGE_7, EDGE_3}, {EDGE_6, EDGE_5, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_9, EDGE_0}, {EDGE_5, EDGE_10, EDGE_6}, {EDGE_8, EDGE_4, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_6, EDGE_5}, {EDGE_1, EDGE_9, EDGE_7}, {EDGE_1, EDGE_7, EDGE_3}, {EDGE_7, EDGE_9, EDGE_4}, {-1, -1, -1}},
    {{EDGE_6, EDGE_1, EDGE_2}, {EDGE_6, EDGE_5, EDGE_1}, {EDGE_4, EDGE_7, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_5}, {EDGE_5, EDGE_2, EDGE_6}, {EDGE_3, EDGE_0, EDGE_4}, {EDGE_3, EDGE_4, EDGE_7}, {-1, -1, -1}},
    {{EDGE_8, EDGE_4, EDGE_7}, {EDGE_9, EDGE_0, EDGE_5}, {EDGE_0, EDGE_6, EDGE_5}, {EDGE_0, EDGE_2, EDGE_6}, {-1, -1, -1}},
    {{EDGE_7, EDGE_3, EDGE_9}, {EDGE_7, EDGE_9, EDGE_4}, {EDGE_3, EDGE_2, EDGE_9}, {EDGE_5, EDGE_9, EDGE_6}, {EDGE_2, EDGE_6, EDGE_9}},
    {{EDGE_3, EDGE_11, EDGE_2}, {EDGE_7, EDGE_8, EDGE_4}, {EDGE_10, EDGE_6, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_10, EDGE_6}, {EDGE_4, EDGE_7, EDGE_2}, {EDGE_4, EDGE_2, EDGE_0}, {EDGE_2, EDGE_7, EDGE_11}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_9}, {EDGE_4, EDGE_7, EDGE_8}, {EDGE_2, EDGE_3, EDGE_11}, {EDGE_5, EDGE_10, EDGE_6}, {-1, -1, -1}},
    {{EDGE_9, EDGE_2, EDGE_1}, {EDGE_9, EDGE_11, EDGE_2}, {EDGE_9, EDGE_4, EDGE_11}, {EDGE_7, EDGE_11, EDGE_4}, {EDGE_5, EDGE_10, EDGE_6}},
    {{EDGE_8, EDGE_4, EDGE_7}, {EDGE_3, EDGE_11, EDGE_5}, {EDGE_3, EDGE_5, EDGE_1}, {EDGE_5, EDGE_11, EDGE_6}, {-1, -1, -1}},
    {{EDGE_5, EDGE_1, EDGE_11}, {EDGE_5, EDGE_11, EDGE_6}, {EDGE_1, EDGE_0, EDGE_11}, {EDGE_7, EDGE_11, EDGE_4}, {EDGE_0, EDGE_4, EDGE_11}},
    {{EDGE_0, EDGE_5, EDGE_9}, {EDGE_0, EDGE_6, EDGE_5}, {EDGE_0, EDGE_3, EDGE_6}, {EDGE_11, EDGE_6, EDGE_3}, {EDGE_8, EDGE_4, EDGE_7}},
    {{EDGE_6, EDGE_5, EDGE_9}, {EDGE_6, EDGE_9, EDGE_11}, {EDGE_4, EDGE_7, EDGE_9}, {EDGE_7, EDGE_11, EDGE_9}, {-1, -1, -1}},
    {{EDGE_10, EDGE_4, EDGE_9}, {EDGE_6, EDGE_4, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_10, EDGE_6}, {EDGE_4, EDGE_9, EDGE_10}, {EDGE_0, EDGE_8, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_0, EDGE_1}, {EDGE_10, EDGE_6, EDGE_0}, {EDGE_6, EDGE_4, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_3, EDGE_1}, {EDGE_8, EDGE_1, EDGE_6}, {EDGE_8, EDGE_6, EDGE_4}, {EDGE_6, EDGE_1, EDGE_10}, {-1, -1, -1}},
    {{EDGE_1, EDGE_4, EDGE_9}, {EDGE_1, EDGE_2, EDGE_4}, {EDGE_2, EDGE_6, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_0, EDGE_8}, {EDGE_1, EDGE_2, EDGE_9}, {EDGE_2, EDGE_4, EDGE_9}, {EDGE_2, EDGE_6, EDGE_4}, {-1, -1, -1}},
    {{EDGE_0, EDGE_2, EDGE_4}, {EDGE_4, EDGE_2, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_3, EDGE_2}, {EDGE_8, EDGE_2, EDGE_4}, {EDGE_4, EDGE_2, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_4, EDGE_9}, {EDGE_10, EDGE_6, EDGE_4}, {EDGE_11, EDGE_2, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_2}, {EDGE_2, EDGE_8, EDGE_11}, {EDGE_4, EDGE_9, EDGE_10}, {EDGE_4, EDGE_10, EDGE_6}, {-1, -1, -1}},
    {{EDGE_3, EDGE_11, EDGE_2}, {EDGE_0, EDGE_1, EDGE_6}, {EDGE_0, EDGE_6, EDGE_4}, {EDGE_6, EDGE_1, EDGE_10}, {-1, -1, -1}},
    {{EDGE_6, EDGE_4, EDGE_1}, {EDGE_6, EDGE_1, EDGE_10}, {EDGE_4, EDGE_8, EDGE_1}, {EDGE_2, EDGE_1, EDGE_11}, {EDGE_8, EDGE_11, EDGE_1}},
    {{EDGE_9, EDGE_6, EDGE_4}, {EDGE_9, EDGE_3, EDGE_6}, {EDGE_9, EDGE_1, EDGE_3}, {EDGE_11, EDGE_6, EDGE_3}, {-1, -1, -1}},
    {{EDGE_8, EDGE_11, EDGE_1}, {EDGE_8, EDGE_1, EDGE_0}, {EDGE_11, EDGE_6, EDGE_1}, {EDGE_9, EDGE_1, EDGE_4}, {EDGE_6, EDGE_4, EDGE_1}},
    {{EDGE_3, EDGE_11, EDGE_6}, {EDGE_3, EDGE_6, EDGE_0}, {EDGE_0, EDGE_6, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_6, EDGE_4, EDGE_8}, {EDGE_11, EDGE_6, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_7, EDGE_10, EDGE_6}, {EDGE_7, EDGE_8, EDGE_10}, {EDGE_8, EDGE_9, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_7, EDGE_3}, {EDGE_0, EDGE_10, EDGE_7}, {EDGE_0, EDGE_9, EDGE_10}, {EDGE_6, EDGE_7, EDGE_10}, {-1, -1, -1}},
    {{EDGE_10, EDGE_6, EDGE_7}, {EDGE_1, EDGE_10, EDGE_7}, {EDGE_1, EDGE_7, EDGE_8}, {EDGE_1, EDGE_8, EDGE_0}, {-1, -1, -1}},
    {{EDGE_10, EDGE_6, EDGE_7}, {EDGE_10, EDGE_7, EDGE_1}, {EDGE_1, EDGE_7, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_6}, {EDGE_1, EDGE_6, EDGE_8}, {EDGE_1, EDGE_8, EDGE_9}, {EDGE_8, EDGE_6, EDGE_7}, {-1, -1, -1}},
    {{EDGE_2, EDGE_6, EDGE_9}, {EDGE_2, EDGE_9, EDGE_1}, {EDGE_6, EDGE_7, EDGE_9}, {EDGE_0, EDGE_9, EDGE_3}, {EDGE_7, EDGE_3, EDGE_9}},
    {{EDGE_7, EDGE_8, EDGE_0}, {EDGE_7, EDGE_0, EDGE_6}, {EDGE_6, EDGE_0, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_7, EDGE_3, EDGE_2}, {EDGE_6, EDGE_7, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_3, EDGE_11}, {EDGE_10, EDGE_6, EDGE_8}, {EDGE_10, EDGE_8, EDGE_9}, {EDGE_8, EDGE_6, EDGE_7}, {-1, -1, -1}},
    {{EDGE_2, EDGE_0, EDGE_7}, {EDGE_2, EDGE_7, EDGE_11}, {EDGE_0, EDGE_9, EDGE_7}, {EDGE_6, EDGE_7, EDGE_10}, {EDGE_9, EDGE_10, EDGE_7}},
    {{EDGE_1, EDGE_8, EDGE_0}, {EDGE_1, EDGE_7, EDGE_8}, {EDGE_1, EDGE_10, EDGE_7}, {EDGE_6, EDGE_7, EDGE_10}, {EDGE_2, EDGE_3, EDGE_11}},
    {{EDGE_11, EDGE_2, EDGE_1}, {EDGE_11, EDGE_1, EDGE_7}, {EDGE_10, EDGE_6, EDGE_1}, {EDGE_6, EDGE_7, EDGE_1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_9, EDGE_6}, {EDGE_8, EDGE_6, EDGE_7}, {EDGE_9, EDGE_1, EDGE_6}, {EDGE_11, EDGE_6, EDGE_3}, {EDGE_1, EDGE_3, EDGE_6}},
    {{EDGE_0, EDGE_9, EDGE_1}, {EDGE_11, EDGE_6, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_7, EDGE_8, EDGE_0}, {EDGE_7, EDGE_0, EDGE_6}, {EDGE_3, EDGE_11, EDGE_0}, {EDGE_11, EDGE_6, EDGE_0}, {-1, -1, -1}},
    {{EDGE_7, EDGE_11, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_7, EDGE_6, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_0, EDGE_8}, {EDGE_11, EDGE_7, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_9}, {EDGE_11, EDGE_7, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_1, EDGE_9}, {EDGE_8, EDGE_3, EDGE_1}, {EDGE_11, EDGE_7, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_1, EDGE_2}, {EDGE_6, EDGE_11, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_10}, {EDGE_3, EDGE_0, EDGE_8}, {EDGE_6, EDGE_11, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_9, EDGE_0}, {EDGE_2, EDGE_10, EDGE_9}, {EDGE_6, EDGE_11, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_6, EDGE_11, EDGE_7}, {EDGE_2, EDGE_10, EDGE_3}, {EDGE_10, EDGE_8, EDGE_3}, {EDGE_10, EDGE_9, EDGE_8}, {-1, -1, -1}},
    {{EDGE_7, EDGE_2, EDGE_3}, {EDGE_6, EDGE_2, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_7, EDGE_0, EDGE_8}, {EDGE_7, EDGE_6, EDGE_0}, {EDGE_6, EDGE_2, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_7, EDGE_6}, {EDGE_2, EDGE_3, EDGE_7}, {EDGE_0, EDGE_1, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_6, EDGE_2}, {EDGE_1, EDGE_8, EDGE_6}, {EDGE_1, EDGE_9, EDGE_8}, {EDGE_8, EDGE_7, EDGE_6}, {-1, -1, -1}},
    {{EDGE_10, EDGE_7, EDGE_6}, {EDGE_10, EDGE_1, EDGE_7}, {EDGE_1, EDGE_3, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_7, EDGE_6}, {EDGE_1, EDGE_7, EDGE_10}, {EDGE_1, EDGE_8, EDGE_7}, {EDGE_1, EDGE_0, EDGE_8}, {-1, -1, -1}},
    {{EDGE_0, EDGE_3, EDGE_7}, {EDGE_0, EDGE_7, EDGE_10}, {EDGE_0, EDGE_10, EDGE_9}, {EDGE_6, EDGE_10, EDGE_7}, {-1, -1, -1}},
    {{EDGE_7, EDGE_6, EDGE_10}, {EDGE_7, EDGE_10, EDGE_8}, {EDGE_8, EDGE_10, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_6, EDGE_8, EDGE_4}, {EDGE_11, EDGE_8, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_6, EDGE_11}, {EDGE_3, EDGE_0, EDGE_6}, {EDGE_0, EDGE_4, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_6, EDGE_11}, {EDGE_8, EDGE_4, EDGE_6}, {EDGE_9, EDGE_0, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_4, EDGE_6}, {EDGE_9, EDGE_6, EDGE_3}, {EDGE_9, EDGE_3, EDGE_1}, {EDGE_11, EDGE_3, EDGE_6}, {-1, -1, -1}},
    {{EDGE_6, EDGE_8, EDGE_4}, {EDGE_6, EDGE_11, EDGE_8}, {EDGE_2, EDGE_10, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_10}, {EDGE_3, EDGE_0, EDGE_11}, {EDGE_0, EDGE_6, EDGE_11}, {EDGE_0, EDGE_4, EDGE_6}, {-1, -1, -1}},
    {{EDGE_4, EDGE_11, EDGE_8}, {EDGE_4, EDGE_6, EDGE_11}, {EDGE_0, EDGE_2, EDGE_9}, {EDGE_2, EDGE_10, EDGE_9}, {-1, -1, -1}},
    {{EDGE_10, EDGE_9, EDGE_3}, {EDGE_10, EDGE_3, EDGE_2}, {EDGE_9, EDGE_4, EDGE_3}, {EDGE_11, EDGE_3, EDGE_6}, {EDGE_4, EDGE_6, EDGE_3}},
    {{EDGE_8, EDGE_2, EDGE_3}, {EDGE_8, EDGE_4, EDGE_2}, {EDGE_4, EDGE_6, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_4, EDGE_2}, {EDGE_4, EDGE_6, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_9, EDGE_0}, {EDGE_2, EDGE_3, EDGE_4}, {EDGE_2, EDGE_4, EDGE_6}, {EDGE_4, EDGE_3, EDGE_8}, {-1, -1, -1}},
    {{EDGE_1, EDGE_9, EDGE_4}, {EDGE_1, EDGE_4, EDGE_2}, {EDGE_2, EDGE_4, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_1, EDGE_3}, {EDGE_8, EDGE_6, EDGE_1}, {EDGE_8, EDGE_4, EDGE_6}, {EDGE_6, EDGE_10, EDGE_1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_1, EDGE_0}, {EDGE_10, EDGE_0, EDGE_6}, {EDGE_6, EDGE_0, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_6, EDGE_3}, {EDGE_4, EDGE_3, EDGE_8}, {EDGE_6, EDGE_10, EDGE_3}, {EDGE_0, EDGE_3, EDGE_9}, {EDGE_10, EDGE_9, EDGE_3}},
    {{EDGE_10, EDGE_9, EDGE_4}, {EDGE_6, EDGE_10, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_9, EDGE_5}, {EDGE_7, EDGE_6, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_3}, {EDGE_4, EDGE_9, EDGE_5}, {EDGE_11, EDGE_7, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_0, EDGE_1}, {EDGE_5, EDGE_4, EDGE_0}, {EDGE_7, EDGE_6, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_7, EDGE_6}, {EDGE_8, EDGE_3, EDGE_4}, {EDGE_3, EDGE_5, EDGE_4}, {EDGE_3, EDGE_1, EDGE_5}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_4}, {EDGE_10, EDGE_1, EDGE_2}, {EDGE_7, EDGE_6, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_6, EDGE_11, EDGE_7}, {EDGE_1, EDGE_2, EDGE_10}, {EDGE_0, EDGE_8, EDGE_3}, {EDGE_4, EDGE_9, EDGE_5}, {-1, -1, -1}},
    {{EDGE_7, EDGE_6, EDGE_11}, {EDGE_5, EDGE_4, EDGE_10}, {EDGE_4, EDGE_2, EDGE_10}, {EDGE_4, EDGE_0, EDGE_2}, {-1, -1, -1}},
    {{EDGE_3, EDGE_4, EDGE_8}, {EDGE_3, EDGE_5, EDGE_4}, {EDGE_3, EDGE_2, EDGE_5}, {EDGE_10, EDGE_5, EDGE_2}, {EDGE_11, EDGE_7, EDGE_6}},
    {{EDGE_7, EDGE_2, EDGE_3}, {EDGE_7, EDGE_6, EDGE_2}, {EDGE_5, EDGE_4, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_4}, {EDGE_0, EDGE_8, EDGE_6}, {EDGE_0, EDGE_6, EDGE_2}, {EDGE_6, EDGE_8, EDGE_7}, {-1, -1, -1}},
    {{EDGE_3, EDGE_6, EDGE_2}, {EDGE_3, EDGE_7, EDGE_6}, {EDGE_1, EDGE_5, EDGE_0}, {EDGE_5, EDGE_4, EDGE_0}, {-1, -1, -1}},
    {{EDGE_6, EDGE_2, EDGE_8}, {EDGE_6, EDGE_8, EDGE_7}, {EDGE_2, EDGE_1, EDGE_8}, {EDGE_4, EDGE_8, EDGE_5}, {EDGE_1, EDGE_5, EDGE_8}},
    {{EDGE_9, EDGE_5, EDGE_4}, {EDGE_10, EDGE_1, EDGE_6}, {EDGE_1, EDGE_7, EDGE_6}, {EDGE_1, EDGE_3, EDGE_7}, {-1, -1, -1}},
    {{EDGE_1, EDGE_6, EDGE_10}, {EDGE_1, EDGE_7, EDGE_6}, {EDGE_1, EDGE_0, EDGE_7}, {EDGE_8, EDGE_7, EDGE_0}, {EDGE_9, EDGE_5, EDGE_4}},
    {{EDGE_4, EDGE_0, EDGE_10}, {EDGE_4, EDGE_10, EDGE_5}, {EDGE_0, EDGE_3, EDGE_10}, {EDGE_6, EDGE_10, EDGE_7}, {EDGE_3, EDGE_7, EDGE_10}},
    {{EDGE_7, EDGE_6, EDGE_10}, {EDGE_7, EDGE_10, EDGE_8}, {EDGE_5, EDGE_4, EDGE_10}, {EDGE_4, EDGE_8, EDGE_10}, {-1, -1, -1}},
    {{EDGE_6, EDGE_9, EDGE_5}, {EDGE_6, EDGE_11, EDGE_9}, {EDGE_11, EDGE_8, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_6, EDGE_11}, {EDGE_0, EDGE_6, EDGE_3}, {EDGE_0, EDGE_5, EDGE_6}, {EDGE_0, EDGE_9, EDGE_5}, {-1, -1, -1}},
    {{EDGE_0, EDGE_11, EDGE_8}, {EDGE_0, EDGE_5, EDGE_11}, {EDGE_0, EDGE_1, EDGE_5}, {EDGE_5, EDGE_6, EDGE_11}, {-1, -1, -1}},
    {{EDGE_6, EDGE_11, EDGE_3}, {EDGE_6, EDGE_3, EDGE_5}, {EDGE_5, EDGE_3, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_10}, {EDGE_9, EDGE_5, EDGE_11}, {EDGE_9, EDGE_11, EDGE_8}, {EDGE_11, EDGE_5, EDGE_6}, {-1, -1, -1}},
    {{EDGE_0, EDGE_11, EDGE_3}, {EDGE_0, EDGE_6, EDGE_11}, {EDGE_0, EDGE_9, EDGE_6}, {EDGE_5, EDGE_6, EDGE_9}, {EDGE_1, EDGE_2, EDGE_10}},
    {{EDGE_11, EDGE_8, EDGE_5}, {EDGE_11, EDGE_5, EDGE_6}, {EDGE_8, EDGE_0, EDGE_5}, {EDGE_10, EDGE_5, EDGE_2}, {EDGE_0, EDGE_2, EDGE_5}},
    {{EDGE_6, EDGE_11, EDGE_3}, {EDGE_6, EDGE_3, EDGE_5}, {EDGE_2, EDGE_10, EDGE_3}, {EDGE_10, EDGE_5, EDGE_3}, {-1, -1, -1}},
    {{EDGE_5, EDGE_8, EDGE_9}, {EDGE_5, EDGE_2, EDGE_8}, {EDGE_5, EDGE_6, EDGE_2}, {EDGE_3, EDGE_8, EDGE_2}, {-1, -1, -1}},
    {{EDGE_9, EDGE_5, EDGE_6}, {EDGE_9, EDGE_6, EDGE_0}, {EDGE_0, EDGE_6, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_5, EDGE_8}, {EDGE_1, EDGE_8, EDGE_0}, {EDGE_5, EDGE_6, EDGE_8}, {EDGE_3, EDGE_8, EDGE_2}, {EDGE_6, EDGE_2, EDGE_8}},
    {{EDGE_1, EDGE_5, EDGE_6}, {EDGE_2, EDGE_1, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_3, EDGE_6}, {EDGE_1, EDGE_6, EDGE_10}, {EDGE_3, EDGE_8, EDGE_6}, {EDGE_5, EDGE_6, EDGE_9}, {EDGE_8, EDGE_9, EDGE_6}},
    {{EDGE_10, EDGE_1, EDGE_0}, {EDGE_10, EDGE_0, EDGE_6}, {EDGE_9, EDGE_5, EDGE_0}, {EDGE_5, EDGE_6, EDGE_0}, {-1, -1, -1}},
    {{EDGE_0, EDGE_3, EDGE_8}, {EDGE_5, EDGE_6, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_5, EDGE_6}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_5, EDGE_10}, {EDGE_7, EDGE_5, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_5, EDGE_10}, {EDGE_11, EDGE_7, EDGE_5}, {EDGE_8, EDGE_3, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_11, EDGE_7}, {EDGE_5, EDGE_10, EDGE_11}, {EDGE_1, EDGE_9, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_10, EDGE_7, EDGE_5}, {EDGE_10, EDGE_11, EDGE_7}, {EDGE_9, EDGE_8, EDGE_1}, {EDGE_8, EDGE_3, EDGE_1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_1, EDGE_2}, {EDGE_11, EDGE_7, EDGE_1}, {EDGE_7, EDGE_5, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_3}, {EDGE_1, EDGE_2, EDGE_7}, {EDGE_1, EDGE_7, EDGE_5}, {EDGE_7, EDGE_2, EDGE_11}, {-1, -1, -1}},
    {{EDGE_9, EDGE_7, EDGE_5}, {EDGE_9, EDGE_2, EDGE_7}, {EDGE_9, EDGE_0, EDGE_2}, {EDGE_2, EDGE_11, EDGE_7}, {-1, -1, -1}},
    {{EDGE_7, EDGE_5, EDGE_2}, {EDGE_7, EDGE_2, EDGE_11}, {EDGE_5, EDGE_9, EDGE_2}, {EDGE_3, EDGE_2, EDGE_8}, {EDGE_9, EDGE_8, EDGE_2}},
    {{EDGE_2, EDGE_5, EDGE_10}, {EDGE_2, EDGE_3, EDGE_5}, {EDGE_3, EDGE_7, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_2, EDGE_0}, {EDGE_8, EDGE_5, EDGE_2}, {EDGE_8, EDGE_7, EDGE_5}, {EDGE_10, EDGE_2, EDGE_5}, {-1, -1, -1}},
    {{EDGE_9, EDGE_0, EDGE_1}, {EDGE_5, EDGE_10, EDGE_3}, {EDGE_5, EDGE_3, EDGE_7}, {EDGE_3, EDGE_10, EDGE_2}, {-1, -1, -1}},
    {{EDGE_9, EDGE_8, EDGE_2}, {EDGE_9, EDGE_2, EDGE_1}, {EDGE_8, EDGE_7, EDGE_2}, {EDGE_10, EDGE_2, EDGE_5}, {EDGE_7, EDGE_5, EDGE_2}},
    {{EDGE_1, EDGE_3, EDGE_5}, {EDGE_3, EDGE_7, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_7}, {EDGE_0, EDGE_7, EDGE_1}, {EDGE_1, EDGE_7, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_0, EDGE_3}, {EDGE_9, EDGE_3, EDGE_5}, {EDGE_5, EDGE_3, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_8, EDGE_7}, {EDGE_5, EDGE_9, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_8, EDGE_4}, {EDGE_5, EDGE_10, EDGE_8}, {EDGE_10, EDGE_11, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_5, EDGE_0, EDGE_4}, {EDGE_5, EDGE_11, EDGE_0}, {EDGE_5, EDGE_10, EDGE_11}, {EDGE_11, EDGE_3, EDGE_0}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_9}, {EDGE_8, EDGE_4, EDGE_10}, {EDGE_8, EDGE_10, EDGE_11}, {EDGE_10, EDGE_4, EDGE_5}, {-1, -1, -1}},
    {{EDGE_10, EDGE_11, EDGE_4}, {EDGE_10, EDGE_4, EDGE_5}, {EDGE_11, EDGE_3, EDGE_4}, {EDGE_9, EDGE_4, EDGE_1}, {EDGE_3, EDGE_1, EDGE_4}},
    {{EDGE_2, EDGE_5, EDGE_1}, {EDGE_2, EDGE_8, EDGE_5}, {EDGE_2, EDGE_11, EDGE_8}, {EDGE_4, EDGE_5, EDGE_8}, {-1, -1, -1}},
    {{EDGE_0, EDGE_4, EDGE_11}, {EDGE_0, EDGE_11, EDGE_3}, {EDGE_4, EDGE_5, EDGE_11}, {EDGE_2, EDGE_11, EDGE_1}, {EDGE_5, EDGE_1, EDGE_11}},
    {{EDGE_0, EDGE_2, EDGE_5}, {EDGE_0, EDGE_5, EDGE_9}, {EDGE_2, EDGE_11, EDGE_5}, {EDGE_4, EDGE_5, EDGE_8}, {EDGE_11, EDGE_8, EDGE_5}},
    {{EDGE_9, EDGE_4, EDGE_5}, {EDGE_2, EDGE_11, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_5, EDGE_10}, {EDGE_3, EDGE_5, EDGE_2}, {EDGE_3, EDGE_4, EDGE_5}, {EDGE_3, EDGE_8, EDGE_4}, {-1, -1, -1}},
    {{EDGE_5, EDGE_10, EDGE_2}, {EDGE_5, EDGE_2, EDGE_4}, {EDGE_4, EDGE_2, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_10, EDGE_2}, {EDGE_3, EDGE_5, EDGE_10}, {EDGE_3, EDGE_8, EDGE_5}, {EDGE_4, EDGE_5, EDGE_8}, {EDGE_0, EDGE_1, EDGE_9}},
    {{EDGE_5, EDGE_10, EDGE_2}, {EDGE_5, EDGE_2, EDGE_4}, {EDGE_1, EDGE_9, EDGE_2}, {EDGE_9, EDGE_4, EDGE_2}, {-1, -1, -1}},
    {{EDGE_8, EDGE_4, EDGE_5}, {EDGE_8, EDGE_5, EDGE_3}, {EDGE_3, EDGE_5, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_4, EDGE_5}, {EDGE_1, EDGE_0, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_8, EDGE_4, EDGE_5}, {EDGE_8, EDGE_5, EDGE_3}, {EDGE_9, EDGE_0, EDGE_5}, {EDGE_0, EDGE_3, EDGE_5}, {-1, -1, -1}},
    {{EDGE_9, EDGE_4, EDGE_5}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_11, EDGE_7}, {EDGE_4, EDGE_9, EDGE_11}, {EDGE_9, EDGE_10, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_8, EDGE_3}, {EDGE_4, EDGE_9, EDGE_7}, {EDGE_9, EDGE_11, EDGE_7}, {EDGE_9, EDGE_10, EDGE_11}, {-1, -1, -1}},
    {{EDGE_1, EDGE_10, EDGE_11}, {EDGE_1, EDGE_11, EDGE_4}, {EDGE_1, EDGE_4, EDGE_0}, {EDGE_7, EDGE_4, EDGE_11}, {-1, -1, -1}},
    {{EDGE_3, EDGE_1, EDGE_4}, {EDGE_3, EDGE_4, EDGE_8}, {EDGE_1, EDGE_10, EDGE_4}, {EDGE_7, EDGE_4, EDGE_11}, {EDGE_10, EDGE_11, EDGE_4}},
    {{EDGE_4, EDGE_11, EDGE_7}, {EDGE_9, EDGE_11, EDGE_4}, {EDGE_9, EDGE_2, EDGE_11}, {EDGE_9, EDGE_1, EDGE_2}, {-1, -1, -1}},
    {{EDGE_9, EDGE_7, EDGE_4}, {EDGE_9, EDGE_11, EDGE_7}, {EDGE_9, EDGE_1, EDGE_11}, {EDGE_2, EDGE_11, EDGE_1}, {EDGE_0, EDGE_8, EDGE_3}},
    {{EDGE_11, EDGE_7, EDGE_4}, {EDGE_11, EDGE_4, EDGE_2}, {EDGE_2, EDGE_4, EDGE_0}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_11, EDGE_7, EDGE_4}, {EDGE_11, EDGE_4, EDGE_2}, {EDGE_8, EDGE_3, EDGE_4}, {EDGE_3, EDGE_2, EDGE_4}, {-1, -1, -1}},
    {{EDGE_2, EDGE_9, EDGE_10}, {EDGE_2, EDGE_7, EDGE_9}, {EDGE_2, EDGE_3, EDGE_7}, {EDGE_7, EDGE_4, EDGE_9}, {-1, -1, -1}},
    {{EDGE_9, EDGE_10, EDGE_7}, {EDGE_9, EDGE_7, EDGE_4}, {EDGE_10, EDGE_2, EDGE_7}, {EDGE_8, EDGE_7, EDGE_0}, {EDGE_2, EDGE_0, EDGE_7}},
    {{EDGE_3, EDGE_7, EDGE_10}, {EDGE_3, EDGE_10, EDGE_2}, {EDGE_7, EDGE_4, EDGE_10}, {EDGE_1, EDGE_10, EDGE_0}, {EDGE_4, EDGE_0, EDGE_10}},
    {{EDGE_1, EDGE_10, EDGE_2}, {EDGE_8, EDGE_7, EDGE_4}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_9, EDGE_1}, {EDGE_4, EDGE_1, EDGE_7}, {EDGE_7, EDGE_1, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_9, EDGE_1}, {EDGE_4, EDGE_1, EDGE_7}, {EDGE_0, EDGE_8, EDGE_1}, {EDGE_8, EDGE_7, EDGE_1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_0, EDGE_3}, {EDGE_7, EDGE_4, EDGE_3}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_4, EDGE_8, EDGE_7}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_10, EDGE_8}, {EDGE_10, EDGE_11, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_0, EDGE_9}, {EDGE_3, EDGE_9, EDGE_11}, {EDGE_11, EDGE_9, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_1, EDGE_10}, {EDGE_0, EDGE_10, EDGE_8}, {EDGE_8, EDGE_10, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_1, EDGE_10}, {EDGE_11, EDGE_3, EDGE_10}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_2, EDGE_11}, {EDGE_1, EDGE_11, EDGE_9}, {EDGE_9, EDGE_11, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_0, EDGE_9}, {EDGE_3, EDGE_9, EDGE_11}, {EDGE_1, EDGE_2, EDGE_9}, {EDGE_2, EDGE_11, EDGE_9}, {-1, -1, -1}},
    {{EDGE_0, EDGE_2, EDGE_11}, {EDGE_8, EDGE_0, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_3, EDGE_2, EDGE_11}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_3, EDGE_8}, {EDGE_2, EDGE_8, EDGE_10}, {EDGE_10, EDGE_8, EDGE_9}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_9, EDGE_10, EDGE_2}, {EDGE_0, EDGE_9, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_2, EDGE_3, EDGE_8}, {EDGE_2, EDGE_8, EDGE_10}, {EDGE_0, EDGE_1, EDGE_8}, {EDGE_1, EDGE_10, EDGE_8}, {-1, -1, -1}},
    {{EDGE_1, EDGE_10, EDGE_2}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_1, EDGE_3, EDGE_8}, {EDGE_9, EDGE_1, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_9, EDGE_1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{EDGE_0, EDGE_3, EDGE_8}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
    {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
};

// the first table index is the cube configuration,
// the second index is for up to four dual points.
// Each value of a table entry encodes the edges with an associated dual point.
// A value of 0 indicates a dummy point.
const int dual_points_list[256][4] =
    {
        {0, 0, 0, 0}, // 0
        {EDGE_0 | EDGE_3 | EDGE_8, 0, 0, 0}, // 1
        {EDGE_0 | EDGE_1 | EDGE_9, 0, 0, 0}, // 2
        {EDGE_1 | EDGE_3 | EDGE_8 | EDGE_9, 0, 0, 0}, // 3
        {EDGE_1 | EDGE_2 | EDGE_10, 0, 0, 0}, // 4
        {EDGE_1 | EDGE_2 | EDGE_10, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 5
        {EDGE_0 | EDGE_2 | EDGE_9 | EDGE_10, 0, 0, 0}, // 6
        {EDGE_2 | EDGE_3 | EDGE_8 | EDGE_9 | EDGE_10, 0, 0, 0}, // 7
        {EDGE_2 | EDGE_3 | EDGE_11, 0, 0, 0}, // 8
        {EDGE_0 | EDGE_2 | EDGE_8 | EDGE_11, 0, 0, 0}, // 9
        {EDGE_0 | EDGE_1 | EDGE_9, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 10
        {EDGE_1 | EDGE_2 | EDGE_8 | EDGE_9 | EDGE_11, 0, 0, 0}, // 11
        {EDGE_1 | EDGE_3 | EDGE_10 | EDGE_11, 0, 0, 0}, // 12
        {EDGE_0 | EDGE_1 | EDGE_8 | EDGE_10 | EDGE_11, 0, 0, 0}, // 13
        {EDGE_0 | EDGE_3 | EDGE_9 | EDGE_10 | EDGE_11, 0, 0, 0}, // 14
        {EDGE_8 | EDGE_9 | EDGE_10 | EDGE_11, 0, 0, 0}, // 15
        {EDGE_4 | EDGE_7 | EDGE_8, 0, 0, 0}, // 16
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_7, 0, 0, 0}, // 17
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 18
        {EDGE_1 | EDGE_3 | EDGE_4 | EDGE_7 | EDGE_9, 0, 0, 0}, // 19
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 20
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_7, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 21
        {EDGE_0 | EDGE_2 | EDGE_9 | EDGE_10, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 22
        {EDGE_2 | EDGE_3 | EDGE_4 | EDGE_7 | EDGE_9 | EDGE_10, 0, 0, 0}, // 23
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 24
        {EDGE_2 | EDGE_4 | EDGE_7 | EDGE_11 | EDGE_0, 0, 0, 0}, // 25
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_2 | EDGE_3 | EDGE_11, EDGE_0 | EDGE_1 | EDGE_9, 0}, // 26
        {EDGE_1 | EDGE_2 | EDGE_4 | EDGE_7 | EDGE_9 | EDGE_11, 0, 0, 0}, // 27
        {EDGE_1 | EDGE_3 | EDGE_10 | EDGE_11, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 28
        {EDGE_0 | EDGE_1 | EDGE_4 | EDGE_7 | EDGE_10 | EDGE_11, 0, 0, 0}, // 29
        {EDGE_0 | EDGE_3 | EDGE_9 | EDGE_10 | EDGE_11, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 30
        {EDGE_4 | EDGE_7 | EDGE_9 | EDGE_10 | EDGE_11, 0, 0, 0}, // 31
        {EDGE_4 | EDGE_5 | EDGE_9, 0, 0, 0}, // 32
        {EDGE_4 | EDGE_5 | EDGE_9, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 33
        {EDGE_0 | EDGE_1 | EDGE_4 | EDGE_5, 0, 0, 0}, // 34
        {EDGE_1 | EDGE_3 | EDGE_4 | EDGE_5 | EDGE_8, 0, 0, 0}, // 35
        {EDGE_4 | EDGE_5 | EDGE_9, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 36
        {EDGE_4 | EDGE_5 | EDGE_9, EDGE_1 | EDGE_2 | EDGE_10, EDGE_0 | EDGE_3 | EDGE_8, 0}, // 37
        {EDGE_0 | EDGE_2 | EDGE_4 | EDGE_5 | EDGE_10, 0, 0, 0}, // 38
        {EDGE_2 | EDGE_3 | EDGE_4 | EDGE_5 | EDGE_8 | EDGE_10, 0, 0, 0}, // 39
        {EDGE_4 | EDGE_5 | EDGE_9, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 40
        {EDGE_0 | EDGE_2 | EDGE_8 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 41
        {EDGE_0 | EDGE_1 | EDGE_4 | EDGE_5, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 42
        {EDGE_1 | EDGE_2 | EDGE_4 | EDGE_5 | EDGE_8 | EDGE_11, 0, 0, 0}, // 43
        {EDGE_1 | EDGE_3 | EDGE_10 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 44
        {EDGE_0 | EDGE_1 | EDGE_8 | EDGE_10 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 45
        {EDGE_0 | EDGE_4 | EDGE_5 | EDGE_3 | EDGE_10 | EDGE_11, 0, 0, 0}, // 46
        {EDGE_4 | EDGE_5 | EDGE_8 | EDGE_10 | EDGE_11, 0, 0, 0}, // 47
        {EDGE_5 | EDGE_7 | EDGE_8 | EDGE_9, 0, 0, 0}, // 48
        {EDGE_0 | EDGE_3 | EDGE_5 | EDGE_7 | EDGE_9, 0, 0, 0}, // 49
        {EDGE_0 | EDGE_1 | EDGE_5 | EDGE_7 | EDGE_8, 0, 0, 0}, // 50
        {EDGE_1 | EDGE_3 | EDGE_5 | EDGE_7, 0, 0, 0}, // 51
        {EDGE_5 | EDGE_7 | EDGE_8 | EDGE_9, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 52
        {EDGE_0 | EDGE_3 | EDGE_5 | EDGE_7 | EDGE_9, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 53
        {EDGE_0 | EDGE_2 | EDGE_5 | EDGE_7 | EDGE_8 | EDGE_10, 0, 0, 0}, // 54
        {EDGE_2 | EDGE_3 | EDGE_5 | EDGE_7 | EDGE_10, 0, 0, 0}, // 55
        {EDGE_5 | EDGE_7 | EDGE_8 | EDGE_9, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 56
        {EDGE_0 | EDGE_2 | EDGE_11 | EDGE_7 | EDGE_5 | EDGE_9, 0, 0, 0}, // 57
        {EDGE_7 | EDGE_8 | EDGE_5 | EDGE_0 | EDGE_1, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 58
        {EDGE_1 | EDGE_2 | EDGE_5 | EDGE_7 | EDGE_11, 0, 0, 0}, // 59
        {EDGE_5 | EDGE_7 | EDGE_8 | EDGE_9, EDGE_1 | EDGE_3 | EDGE_10 | EDGE_11, 0, 0}, // 60
        {EDGE_1 | EDGE_10 | EDGE_5 | EDGE_9 | EDGE_0 | EDGE_11 | EDGE_7, 0, 0, 0}, // 61
        {EDGE_11 | EDGE_3 | EDGE_7 | EDGE_8 | EDGE_5 | EDGE_0 | EDGE_10, 0, 0, 0}, // 62
        {EDGE_5 | EDGE_7 | EDGE_10 | EDGE_11, 0, 0, 0}, // 63
        {EDGE_5 | EDGE_6 | EDGE_10, 0, 0, 0}, // 64
        {EDGE_5 | EDGE_6 | EDGE_10, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 65
        {EDGE_5 | EDGE_6 | EDGE_10, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 66
        {EDGE_1 | EDGE_3 | EDGE_8 | EDGE_9, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 67
        {EDGE_1 | EDGE_2 | EDGE_5 | EDGE_6, 0, 0, 0}, // 68
        {EDGE_1 | EDGE_2 | EDGE_5 | EDGE_6, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 69
        {EDGE_0 | EDGE_2 | EDGE_5 | EDGE_6 | EDGE_9, 0, 0, 0}, // 70
        {EDGE_3 | EDGE_8 | EDGE_9 | EDGE_2 | EDGE_6 | EDGE_5, 0, 0, 0}, // 71
        {EDGE_5 | EDGE_6 | EDGE_10, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 72
        {EDGE_0 | EDGE_2 | EDGE_8 | EDGE_11, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 73
        {EDGE_0 | EDGE_1 | EDGE_9, EDGE_5 | EDGE_6 | EDGE_10, EDGE_2 | EDGE_3 | EDGE_11, 0}, // 74
        {EDGE_1 | EDGE_2 | EDGE_8 | EDGE_9 | EDGE_11, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 75
        {EDGE_1 | EDGE_5 | EDGE_6 | EDGE_3 | EDGE_11, 0, 0, 0}, // 76
        {EDGE_0 | EDGE_8 | EDGE_11 | EDGE_6 | EDGE_5 | EDGE_1 | EDGE_0, 0, 0, 0}, // 77
        {EDGE_5 | EDGE_6 | EDGE_3 | EDGE_11 | EDGE_0 | EDGE_9, 0, 0, 0}, // 78
        {EDGE_8 | EDGE_9 | EDGE_11 | EDGE_5 | EDGE_6, 0, 0, 0}, // 79
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 80
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_7, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 81
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_0 | EDGE_1 | EDGE_9, EDGE_5 | EDGE_6 | EDGE_10, 0}, // 82
        {EDGE_4 | EDGE_7 | EDGE_3 | EDGE_1 | EDGE_9, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 83
        {EDGE_1 | EDGE_2 | EDGE_5 | EDGE_6, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 84
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_7, EDGE_1 | EDGE_2 | EDGE_5 | EDGE_6, 0, 0}, // 85
        {EDGE_6 | EDGE_5 | EDGE_0 | EDGE_2 | EDGE_9, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 86
        {EDGE_7 | EDGE_3 | EDGE_4 | EDGE_6 | EDGE_5 | EDGE_2 | EDGE_9, 0, 0, 0}, // 87
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_5 | EDGE_6 | EDGE_10, EDGE_2 | EDGE_3 | EDGE_11, 0}, // 88
        {EDGE_4 | EDGE_7 | EDGE_11 | EDGE_2 | EDGE_0, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 89
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_2 | EDGE_3 | EDGE_11, EDGE_5 | EDGE_6 | EDGE_10, EDGE_0 | EDGE_1 | EDGE_9}, // 90
        {EDGE_2 | EDGE_11 | EDGE_7 | EDGE_4 | EDGE_1 | EDGE_9, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 91
        {EDGE_11 | EDGE_3 | EDGE_6 | EDGE_5 | EDGE_1, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 92
        {EDGE_7 | EDGE_4 | EDGE_11 | EDGE_6 | EDGE_5 | EDGE_0 | EDGE_1, 0, 0, 0}, // 93
        {EDGE_11 | EDGE_3 | EDGE_5 | EDGE_6 | EDGE_0 | EDGE_9, EDGE_4 | EDGE_7 | EDGE_8, 0, 0}, // 94
        {EDGE_4 | EDGE_7 | EDGE_11 | EDGE_5 | EDGE_6 | EDGE_9, 0, 0, 0}, // 95
        {EDGE_4 | EDGE_6 | EDGE_9 | EDGE_10, 0, 0, 0}, // 96
        {EDGE_4 | EDGE_6 | EDGE_9 | EDGE_10, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 97
        {EDGE_0 | EDGE_1 | EDGE_4 | EDGE_6 | EDGE_10, 0, 0, 0}, // 98
        {EDGE_3 | EDGE_8 | EDGE_1 | EDGE_4 | EDGE_6 | EDGE_10, 0, 0, 0}, // 99
        {EDGE_6 | EDGE_2 | EDGE_1 | EDGE_4 | EDGE_9, 0, 0, 0}, // 100
        {EDGE_6 | EDGE_2 | EDGE_1 | EDGE_4 | EDGE_9, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 101
        {EDGE_0 | EDGE_2 | EDGE_4 | EDGE_6, 0, 0, 0}, // 102
        {EDGE_3 | EDGE_8 | EDGE_4 | EDGE_6 | EDGE_2, 0, 0, 0}, // 103
        {EDGE_4 | EDGE_9 | EDGE_6 | EDGE_10, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 104
        {EDGE_4 | EDGE_9 | EDGE_6 | EDGE_10, EDGE_0 | EDGE_2 | EDGE_8 | EDGE_11, 0, 0}, // 105
        {EDGE_6 | EDGE_10 | EDGE_4 | EDGE_0 | EDGE_1, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 106
        {EDGE_2 | EDGE_11 | EDGE_8 | EDGE_1 | EDGE_4 | EDGE_10 | EDGE_6, 0, 0, 0}, // 107
        {EDGE_3 | EDGE_11 | EDGE_6 | EDGE_4 | EDGE_1 | EDGE_9, 0, 0, 0}, // 108
        {EDGE_8 | EDGE_0 | EDGE_11 | EDGE_6 | EDGE_4 | EDGE_9 | EDGE_1, 0, 0, 0}, // 109
        {EDGE_11 | EDGE_3 | EDGE_6 | EDGE_4 | EDGE_0, 0, 0, 0}, // 110
        {EDGE_4 | EDGE_6 | EDGE_8 | EDGE_11, 0, 0, 0}, // 111
        {EDGE_7 | EDGE_6 | EDGE_8 | EDGE_9 | EDGE_10, 0, 0, 0}, // 112
        {EDGE_3 | EDGE_7 | EDGE_0 | EDGE_6 | EDGE_10 | EDGE_9, 0, 0, 0}, // 113
        {EDGE_7 | EDGE_8 | EDGE_0 | EDGE_1 | EDGE_10 | EDGE_6, 0, 0, 0}, // 114
        {EDGE_7 | EDGE_3 | EDGE_6 | EDGE_10 | EDGE_1, 0, 0, 0}, // 115
        {EDGE_7 | EDGE_8 | EDGE_6 | EDGE_9 | EDGE_2 | EDGE_1, 0, 0, 0}, // 116
        {EDGE_7 | EDGE_3 | EDGE_0 | EDGE_9 | EDGE_1 | EDGE_2 | EDGE_6, 0, 0, 0}, // 117
        {EDGE_7 | EDGE_8 | EDGE_0 | EDGE_2 | EDGE_6, 0, 0, 0}, // 118
        {EDGE_7 | EDGE_6 | EDGE_3 | EDGE_2, 0, 0, 0}, // 119
        {EDGE_7 | EDGE_8 | EDGE_9 | EDGE_6 | EDGE_10, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 120
        {EDGE_7 | EDGE_11 | EDGE_2 | EDGE_0 | EDGE_6 | EDGE_10 | EDGE_9, 0, 0, 0}, // 121
        {EDGE_7 | EDGE_8 | EDGE_6 | EDGE_10 | EDGE_0 | EDGE_1, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 122
        {EDGE_7 | EDGE_6 | EDGE_10 | EDGE_1 | EDGE_2 | EDGE_11, 0, 0, 0}, // 123
        {EDGE_7 | EDGE_8 | EDGE_11 | EDGE_6 | EDGE_3 | EDGE_9 | EDGE_1, 0, 0, 0}, // 124
        {EDGE_11 | EDGE_6 | EDGE_7, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 125
        {EDGE_7 | EDGE_8 | EDGE_11 | EDGE_3 | EDGE_6 | EDGE_0, 0, 0, 0}, // 126
        {EDGE_7 | EDGE_6 | EDGE_11, 0, 0, 0}, // 127
        {EDGE_7 | EDGE_6 | EDGE_11, 0, 0, 0}, // 128
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 129
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 130
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_1 | EDGE_3 | EDGE_8 | EDGE_9, 0, 0}, // 131
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 132
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_1 | EDGE_2 | EDGE_10, EDGE_0 | EDGE_3 | EDGE_8, 0}, // 133
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_0 | EDGE_2 | EDGE_9 | EDGE_10, 0, 0}, // 134
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_2 | EDGE_3 | EDGE_8 | EDGE_9 | EDGE_10, 0, 0}, // 135
        {EDGE_2 | EDGE_3 | EDGE_6 | EDGE_7, 0, 0, 0}, // 136
        {EDGE_0 | EDGE_2 | EDGE_6 | EDGE_7 | EDGE_8, 0, 0, 0}, // 137
        {EDGE_2 | EDGE_3 | EDGE_6 | EDGE_7, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 138
        {EDGE_1 | EDGE_2 | EDGE_6 | EDGE_7 | EDGE_8 | EDGE_9, 0, 0, 0}, // 139
        {EDGE_7 | EDGE_6 | EDGE_10 | EDGE_1 | EDGE_3, 0, 0, 0}, // 140
        {EDGE_7 | EDGE_6 | EDGE_8 | EDGE_0 | EDGE_10 | EDGE_1, 0, 0, 0}, // 141
        {EDGE_3 | EDGE_6 | EDGE_7 | EDGE_0 | EDGE_9 | EDGE_10, 0, 0, 0}, // 142
        {EDGE_7 | EDGE_6 | EDGE_8 | EDGE_9 | EDGE_10, 0, 0, 0}, // 143
        {EDGE_4 | EDGE_6 | EDGE_8 | EDGE_11, 0, 0, 0}, // 144
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_6 | EDGE_11, 0, 0, 0}, // 145
        {EDGE_4 | EDGE_6 | EDGE_8 | EDGE_11, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 146
        {EDGE_6 | EDGE_11 | EDGE_3 | EDGE_4 | EDGE_9 | EDGE_1, 0, 0, 0}, // 147
        {EDGE_4 | EDGE_6 | EDGE_8 | EDGE_11, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 148
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_6 | EDGE_11, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 149
        {EDGE_4 | EDGE_6 | EDGE_8 | EDGE_11, EDGE_0 | EDGE_2 | EDGE_9 | EDGE_10, 0, 0}, // 150
        {EDGE_11 | EDGE_6 | EDGE_3 | EDGE_4 | EDGE_9 | EDGE_10 | EDGE_2, 0, 0, 0}, // 151
        {EDGE_4 | EDGE_6 | EDGE_2 | EDGE_3 | EDGE_8, 0, 0, 0}, // 152
        {EDGE_0 | EDGE_2 | EDGE_4 | EDGE_6, 0, 0, 0}, // 153
        {EDGE_4 | EDGE_6 | EDGE_2 | EDGE_3 | EDGE_8, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 154
        {EDGE_4 | EDGE_6 | EDGE_2 | EDGE_1 | EDGE_9, 0, 0, 0}, // 155
        {EDGE_4 | EDGE_6 | EDGE_10 | EDGE_1 | EDGE_8 | EDGE_3, 0, 0, 0}, // 156
        {EDGE_6 | EDGE_4 | EDGE_0 | EDGE_1 | EDGE_10, 0, 0, 0}, // 157
        {EDGE_9 | EDGE_0 | EDGE_10 | EDGE_6 | EDGE_4 | EDGE_8 | EDGE_3, 0, 0, 0}, // 158
        {EDGE_4 | EDGE_6 | EDGE_9 | EDGE_10, 0, 0, 0}, // 159
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 160
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_9, EDGE_0 | EDGE_3 | EDGE_8, 0}, // 161
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_0 | EDGE_1 | EDGE_4 | EDGE_5, 0, 0}, // 162
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_8 | EDGE_3 | EDGE_1 | EDGE_5 | EDGE_4, 0, 0}, // 163
        {EDGE_6 | EDGE_7 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_9, EDGE_1 | EDGE_2 | EDGE_10, 0}, // 164
        {EDGE_6 | EDGE_7 | EDGE_11, EDGE_0 | EDGE_3 | EDGE_8, EDGE_1 | EDGE_2 | EDGE_10, EDGE_4 | EDGE_5 | EDGE_9}, // 165
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_4 | EDGE_5 | EDGE_0 | EDGE_10 | EDGE_2, 0, 0}, // 166
        {EDGE_7 | EDGE_6 | EDGE_11, EDGE_3 | EDGE_8 | EDGE_4 | EDGE_5 | EDGE_2 | EDGE_10, 0, 0}, // 167
        {EDGE_2 | EDGE_3 | EDGE_6 | EDGE_7, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 168
        {EDGE_0 | EDGE_2 | EDGE_6 | EDGE_7 | EDGE_8, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 169
        {EDGE_2 | EDGE_3 | EDGE_6 | EDGE_7, EDGE_0 | EDGE_1 | EDGE_4 | EDGE_5, 0, 0}, // 170
        {EDGE_7 | EDGE_6 | EDGE_2 | EDGE_8 | EDGE_4 | EDGE_5 | EDGE_1, 0, 0, 0}, // 171
        {EDGE_6 | EDGE_7 | EDGE_3 | EDGE_10 | EDGE_1, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 172
        {EDGE_0 | EDGE_8 | EDGE_6 | EDGE_7 | EDGE_1 | EDGE_10, EDGE_4 | EDGE_5 | EDGE_9, 0, 0}, // 173
        {EDGE_7 | EDGE_6 | EDGE_3 | EDGE_10 | EDGE_0 | EDGE_4 | EDGE_5, 0, 0, 0}, // 174
        {EDGE_8 | EDGE_7 | EDGE_6 | EDGE_10 | EDGE_4 | EDGE_5, 0, 0, 0}, // 175
        {EDGE_11 | EDGE_6 | EDGE_5 | EDGE_9 | EDGE_8, 0, 0, 0}, // 176
        {EDGE_11 | EDGE_6 | EDGE_5 | EDGE_9 | EDGE_0 | EDGE_3, 0, 0, 0}, // 177
        {EDGE_11 | EDGE_6 | EDGE_5 | EDGE_8 | EDGE_0 | EDGE_1, 0, 0, 0}, // 178
        {EDGE_11 | EDGE_6 | EDGE_5 | EDGE_1 | EDGE_3, 0, 0, 0}, // 179
        {EDGE_11 | EDGE_6 | EDGE_5 | EDGE_9 | EDGE_8, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 180
        {EDGE_6 | EDGE_11 | EDGE_0 | EDGE_3 | EDGE_5 | EDGE_9, EDGE_1 | EDGE_10 | EDGE_2, 0, 0}, // 181
        {EDGE_11 | EDGE_6 | EDGE_5 | EDGE_10 | EDGE_2 | EDGE_8 | EDGE_0, 0, 0, 0}, // 182
        {EDGE_6 | EDGE_11 | EDGE_3 | EDGE_2 | EDGE_10 | EDGE_5, 0, 0, 0}, // 183
        {EDGE_2 | EDGE_3 | EDGE_6 | EDGE_5 | EDGE_9 | EDGE_8, 0, 0, 0}, // 184
        {EDGE_0 | EDGE_2 | EDGE_6 | EDGE_5 | EDGE_9, 0, 0, 0}, // 185
        {EDGE_2 | EDGE_6 | EDGE_5 | EDGE_1 | EDGE_8 | EDGE_0 | EDGE_3, 0, 0, 0}, // 186
        {EDGE_1 | EDGE_2 | EDGE_5 | EDGE_6, 0, 0, 0}, // 187
        {EDGE_6 | EDGE_5 | EDGE_10 | EDGE_3 | EDGE_1 | EDGE_9 | EDGE_8, 0, 0, 0}, // 188
        {EDGE_6 | EDGE_5 | EDGE_9 | EDGE_0 | EDGE_1 | EDGE_10, 0, 0, 0}, // 189
        {EDGE_0 | EDGE_3 | EDGE_8, EDGE_5 | EDGE_6 | EDGE_10, 0, 0}, // 190
        {EDGE_5 | EDGE_6 | EDGE_10, 0, 0, 0}, // 191
        {EDGE_5 | EDGE_7 | EDGE_10 | EDGE_11, 0, 0, 0}, // 192
        {EDGE_5 | EDGE_7 | EDGE_10 | EDGE_11, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 193
        {EDGE_5 | EDGE_7 | EDGE_10 | EDGE_11, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 194
        {EDGE_5 | EDGE_7 | EDGE_10 | EDGE_11, EDGE_1 | EDGE_3 | EDGE_8 | EDGE_9, 0, 0}, // 195
        {EDGE_11 | EDGE_7 | EDGE_5 | EDGE_2 | EDGE_1, 0, 0, 0}, // 196
        {EDGE_11 | EDGE_7 | EDGE_5 | EDGE_2 | EDGE_1, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 197
        {EDGE_11 | EDGE_7 | EDGE_5 | EDGE_2 | EDGE_0 | EDGE_9, 0, 0, 0}, // 198
        {EDGE_3 | EDGE_8 | EDGE_11 | EDGE_7 | EDGE_5 | EDGE_2 | EDGE_9, 0, 0, 0}, // 199
        {EDGE_7 | EDGE_5 | EDGE_10 | EDGE_2 | EDGE_3, 0, 0, 0}, // 200
        {EDGE_7 | EDGE_5 | EDGE_10 | EDGE_2 | EDGE_0 | EDGE_8, 0, 0, 0}, // 201
        {EDGE_7 | EDGE_5 | EDGE_10 | EDGE_2 | EDGE_3, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 202
        {EDGE_7 | EDGE_5 | EDGE_10 | EDGE_2 | EDGE_8 | EDGE_9 | EDGE_1, 0, 0, 0}, // 203
        {EDGE_1 | EDGE_3 | EDGE_5 | EDGE_7, 0, 0, 0}, // 204
        {EDGE_0 | EDGE_1 | EDGE_5 | EDGE_7 | EDGE_8, 0, 0, 0}, // 205
        {EDGE_3 | EDGE_7 | EDGE_5 | EDGE_0 | EDGE_9, 0, 0, 0}, // 206
        {EDGE_5 | EDGE_7 | EDGE_8 | EDGE_9, 0, 0, 0}, // 207
        {EDGE_4 | EDGE_8 | EDGE_5 | EDGE_10 | EDGE_11, 0, 0, 0}, // 208
        {EDGE_0 | EDGE_3 | EDGE_11 | EDGE_4 | EDGE_5 | EDGE_10, 0, 0, 0}, // 209
        {EDGE_4 | EDGE_8 | EDGE_11 | EDGE_10 | EDGE_5, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 210
        {EDGE_4 | EDGE_5 | EDGE_10 | EDGE_1 | EDGE_9 | EDGE_11 | EDGE_3, 0, 0, 0}, // 211
        {EDGE_4 | EDGE_8 | EDGE_11 | EDGE_5 | EDGE_2 | EDGE_1, 0, 0, 0}, // 212
        {EDGE_11 | EDGE_3 | EDGE_2 | EDGE_4 | EDGE_5 | EDGE_1 | EDGE_0, 0, 0, 0}, // 213
        {EDGE_11 | EDGE_8 | EDGE_2 | EDGE_4 | EDGE_0 | EDGE_9 | EDGE_5, 0, 0, 0}, // 214
        {EDGE_4 | EDGE_5 | EDGE_9, EDGE_2 | EDGE_3 | EDGE_11, 0, 0}, // 215
        {EDGE_4 | EDGE_8 | EDGE_3 | EDGE_2 | EDGE_10 | EDGE_5, 0, 0, 0}, // 216
        {EDGE_5 | EDGE_10 | EDGE_0 | EDGE_2 | EDGE_4, 0, 0, 0}, // 217
        {EDGE_4 | EDGE_8 | EDGE_3 | EDGE_2 | EDGE_5 | EDGE_10, EDGE_0 | EDGE_1 | EDGE_9, 0, 0}, // 218
        {EDGE_4 | EDGE_5 | EDGE_10 | EDGE_2 | EDGE_1 | EDGE_9, 0, 0, 0}, // 219
        {EDGE_4 | EDGE_8 | EDGE_5 | EDGE_1 | EDGE_3, 0, 0, 0}, // 220
        {EDGE_0 | EDGE_1 | EDGE_4 | EDGE_5, 0, 0, 0}, // 221
        {EDGE_4 | EDGE_8 | EDGE_3 | EDGE_5 | EDGE_0 | EDGE_9, 0, 0, 0}, // 222
        {EDGE_4 | EDGE_5 | EDGE_9, 0, 0, 0}, // 223
        {EDGE_4 | EDGE_9 | EDGE_10 | EDGE_11 | EDGE_7, 0, 0, 0}, // 224
        {EDGE_4 | EDGE_9 | EDGE_10 | EDGE_11 | EDGE_7, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 225
        {EDGE_7 | EDGE_11 | EDGE_10 | EDGE_4 | EDGE_0 | EDGE_1, 0, 0, 0}, // 226
        {EDGE_7 | EDGE_11 | EDGE_10 | EDGE_1 | EDGE_4 | EDGE_8 | EDGE_3, 0, 0, 0}, // 227
        {EDGE_7 | EDGE_11 | EDGE_4 | EDGE_9 | EDGE_2 | EDGE_1, 0, 0, 0}, // 228
        {EDGE_7 | EDGE_11 | EDGE_4 | EDGE_9 | EDGE_2 | EDGE_1, EDGE_0 | EDGE_3 | EDGE_8, 0, 0}, // 229
        {EDGE_7 | EDGE_11 | EDGE_2 | EDGE_0 | EDGE_4, 0, 0, 0}, // 230
        {EDGE_7 | EDGE_11 | EDGE_3 | EDGE_8 | EDGE_4 | EDGE_2, 0, 0, 0}, // 231
        {EDGE_2 | EDGE_3 | EDGE_10 | EDGE_9 | EDGE_4 | EDGE_7, 0, 0, 0}, // 232
        {EDGE_7 | EDGE_8 | EDGE_4 | EDGE_2 | EDGE_0 | EDGE_10 | EDGE_9, 0, 0, 0}, // 233
        {EDGE_7 | EDGE_4 | EDGE_3 | EDGE_2 | EDGE_0 | EDGE_1 | EDGE_10, 0, 0, 0}, // 234
        {EDGE_4 | EDGE_7 | EDGE_8, EDGE_1 | EDGE_2 | EDGE_10, 0, 0}, // 235
        {EDGE_7 | EDGE_3 | EDGE_1 | EDGE_4 | EDGE_9, 0, 0, 0}, // 236
        {EDGE_7 | EDGE_4 | EDGE_8 | EDGE_0 | EDGE_1 | EDGE_9, 0, 0, 0}, // 237
        {EDGE_0 | EDGE_3 | EDGE_4 | EDGE_7, 0, 0, 0}, // 238
        {EDGE_4 | EDGE_7 | EDGE_8, 0, 0, 0}, // 239
        {EDGE_8 | EDGE_9 | EDGE_10 | EDGE_11, 0, 0, 0}, // 240
        {EDGE_9 | EDGE_10 | EDGE_11 | EDGE_0 | EDGE_3, 0, 0, 0}, // 241
        {EDGE_8 | EDGE_10 | EDGE_11 | EDGE_0 | EDGE_1, 0, 0, 0}, // 242
        {EDGE_1 | EDGE_3 | EDGE_10 | EDGE_11, 0, 0, 0}, // 243
        {EDGE_8 | EDGE_9 | EDGE_11 | EDGE_1 | EDGE_2, 0, 0, 0}, // 244
        {EDGE_11 | EDGE_9 | EDGE_3 | EDGE_0 | EDGE_1 | EDGE_2, 0, 0, 0}, // 245
        {EDGE_0 | EDGE_2 | EDGE_8 | EDGE_11, 0, 0, 0}, // 246
        {EDGE_2 | EDGE_3 | EDGE_11, 0, 0, 0}, // 247
        {EDGE_3 | EDGE_2 | EDGE_8 | EDGE_9 | EDGE_10, 0, 0, 0}, // 248
        {EDGE_0 | EDGE_2 | EDGE_9 | EDGE_10, 0, 0, 0}, // 249
        {EDGE_8 | EDGE_0 | EDGE_3 | EDGE_1 | EDGE_2 | EDGE_10, 0, 0, 0}, // 250
        {EDGE_1 | EDGE_2 | EDGE_10, 0, 0, 0}, // 251
        {EDGE_1 | EDGE_3 | EDGE_8 | EDGE_9, 0, 0, 0}, // 252
        {EDGE_0 | EDGE_1 | EDGE_9, 0, 0, 0}, // 253
        {EDGE_0 | EDGE_3 | EDGE_8, 0, 0, 0}, // 254
        {0, 0, 0, 0} // 255
};
} // namespace gris

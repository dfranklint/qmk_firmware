/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// #ifdef RGB_MATRIX_ENABLE
#include "quantum/rgb_matrix/rgb_matrix.h"
// #endif  // RGB_MATRIX_ENABLE

/* combination keys */
enum combos {
  LCRC_MC,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM middle_click_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};


combo_t key_combos[COMBO_LENGTH] = {
  [LCRC_MC] = COMBO(middle_click_combo, KC_BTN3),
};

/* keymaps */
enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_SEL,
    LAYER_AOE2_BASE,
    LAYER_AOE2_GROUPSELECT,
    LAYER_AOE2_GROUPCREATE,
    LAYER_AOE2_GROUPAPPEND,
    LAYER_AOE2_CYCLE
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, MO(LAYER_SEL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                    KC_LSFT, LT(LAYER_SYM, KC_TAB),  KC_LGUI,    MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,     LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_GRV, KC_CIRC, KC_LCBR, KC_AMPR, KC_RCBR, KC_MINS,     KC_PIPE,   KC_LBRC,   KC_DQT,   KC_RBRC, KC_COLN, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_EXLM, KC_LPRN, KC_ASTR, KC_RPRN, KC_UNDS,    KC_EQL,   KC_LT,   KC_QUOT,   KC_GT, KC_SCLN, KC_RSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, KC_PERC, KC_AT, KC_HASH, KC_DLR, KC_SLSH,       KC_BSLS,   KC_PLUS,   KC_COMM,   KC_DOT, KC_QUES, KC_RCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LSFT, XXXXXXX, KC_LGUI,    MO(LAYER_NUM), KC_SPC,
                                           KC_LALT, KC_LCTL,    LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, C(KC_PLUS), C(KC_MINS), XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, XXXXXXX, KC_HOME, KC_INS, KC_END,   XXXXXXX,      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_VOLD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,     LALT(KC_LEFT), RCS(KC_TAB),  KC_PGDN, KC_PGUP, LCTL(KC_TAB), LALT(KC_RIGHT),
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LSFT, KC_TAB, XXXXXXX,    XXXXXXX, KC_SPC,
                                           KC_LALT, KC_LCTL,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_CIRC,   KC_SLSH,   KC_PAST,  KC_PMNS,  KC_EQL, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PLUS, KC_7, KC_8, KC_9, KC_LPRN, KC_RPRN,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_MINS, KC_4, KC_5, KC_6, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    KC_0,   KC_1, KC_2, KC_3, KC_LSFT, KC_DOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_LSFT, KC_TAB, XXXXXXX,    XXXXXXX, XXXXXXX,
                                           KC_LALT, KC_LCTL,    KC_LGUI
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_AOE2_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, TG(LAYER_AOE2_BASE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        XXXXXXX,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        MO(LAYER_AOE2_GROUPAPPEND),KC_A,KC_S,KC_D,KC_F,KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_BSPC, KC_DEL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        XXXXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_BTN1,  KC_BTN2, DRGSCRL, KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
     KC_LSFT, MO(LAYER_AOE2_CYCLE),MO(LAYER_AOE2_GROUPSELECT),     MO(LAYER_NUM),  KC_SPC,
                                           KC_LALT, KC_LCTL,       LT(LAYER_NAV, KC_ENT)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_AOE2_GROUPSELECT] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────────╮
        XXXXXXX,   RCS(KC_1),  RCS(KC_2),  RCS(KC_3),  RCS(KC_4),  RCS(KC_5),            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   RCS(KC_6),  RCS(KC_7),  RCS(KC_8),  RCS(KC_9),  RCS(KC_F10),          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   MEH(KC_1),  MEH(KC_2),  MEH(KC_3),  MEH(KC_4),  MEH(KC_5),            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   MEH(KC_6),  MEH(KC_7),  MEH(KC_8),  MEH(KC_9),  MEH(KC_F10),          XXXXXXX,    XXXXXXX,    KC_BTN1,    KC_BTN2,    DRGSCRL,    XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────╯
                                                       KC_LSFT, XXXXXXX,  XXXXXXX,       MO(LAYER_NUM),  KC_SPC,
                                             KC_LALT,  MO(LAYER_AOE2_GROUPCREATE),       LT(LAYER_NAV, KC_ENT)
  //                                           ╰──────────────────────────────────╯ ╰────────────────────────────────╯
  ),
  [LAYER_AOE2_GROUPCREATE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────────╮
        XXXXXXX,   LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5),           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0),           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   LCA(KC_1),  LCA(KC_2),  LCA(KC_3),  LCA(KC_4),  LCA(KC_5),            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   LCA(KC_6),  LCA(KC_7),  LCA(KC_8),  LCA(KC_9),  LCA(KC_0),            XXXXXXX,    XXXXXXX,    KC_BTN1,    KC_BTN2,    DRGSCRL,    XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────╯
                                                       KC_LSFT, XXXXXXX,  XXXXXXX,       MO(LAYER_NUM),  KC_SPC,
                                                                KC_LALT,  KC_LCTL,       LT(LAYER_NAV, KC_ENT)
  //                                           ╰──────────────────────────────────╯ ╰────────────────────────────────╯
  ),
  [LAYER_AOE2_GROUPAPPEND] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────────╮
        XXXXXXX,   LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   LSA(KC_1),  LSA(KC_2),  LSA(KC_3),  LSA(KC_4),  LSA(KC_5),            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        XXXXXXX,   LSA(KC_6),  LSA(KC_7),  LSA(KC_8),  LSA(KC_9),  LSA(KC_0),            XXXXXXX,    XXXXXXX,    KC_BTN1,    KC_BTN2,    DRGSCRL,    XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────╯
                                                       KC_LSFT, XXXXXXX,  XXXXXXX,       MO(LAYER_NUM),  KC_SPC,
                                                                KC_LALT,  KC_LCTL,       LT(LAYER_NAV, KC_ENT)
  //                                           ╰──────────────────────────────────╯ ╰────────────────────────────────╯
  ),
  [LAYER_AOE2_CYCLE] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────────────────╮
        XXXXXXX,   LCTL(KC_N), LCTL(KC_T), LCA(KC_COMM), LCTL(KC_D), LCTL(KC_M),         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        LALT(KC_N),LCTL(KC_B), LCTL(KC_A), LCTL(KC_L),   LCTL(KC_K), LCTL(KC_Y),         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        LALT(KC_C),LCTL(KC_G), KC_SPC,     KC_H,         KC_DOT,     KC_COMM,            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  // ├────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────┤
        LALT(KC_R),LCTL(KC_Z), LCTL(KC_I), LCTL(KC_V),   LCTL(KC_S), LCTL(KC_U),         XXXXXXX,    XXXXXXX,    KC_BTN1,    KC_BTN2,    DRGSCRL,    XXXXXXX,
  // ╰────────────────────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────────────────╯
                                                       XXXXXXX, XXXXXXX,  XXXXXXX,       MO(LAYER_NUM),  KC_SPC,
                                                                KC_LSFT,  XXXXXXX,       LT(LAYER_NAV, KC_ENT)
  //                                           ╰──────────────────────────────────╯ ╰────────────────────────────────╯
  ),
  [LAYER_SEL] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────╮
       TG(LAYER_BASE),        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       TG(LAYER_AOE2_BASE),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────╯
                                                  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                                                          XXXXXXX, XXXXXXX,    XXXXXXX
  //                                           ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

/* rgb layers */
layer_state_t layer_state_set_user(layer_state_t state) {
   #ifdef RGB_MATRIX_ENABLE
     switch (biton32(state)) {
          case LAYER_NAV:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_nav_effect);
               break;
          case LAYER_BASE:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_base_effect);
               break;
          case LAYER_SYM:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_sym_effect);
               break;
          case LAYER_NUM:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_num_effect);
               break;
          case LAYER_SEL:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_sel_effect);
               break;
          case LAYER_AOE2_BASE:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_base_effect);
               break;
          case LAYER_AOE2_GROUPSELECT:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_groupselect_effect);
               break;
          case LAYER_AOE2_GROUPCREATE:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_groupcreate_effect);
               break;
          case LAYER_AOE2_GROUPAPPEND:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_groupappend_effect);
               break;
          case LAYER_AOE2_CYCLE:
               rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_aoe2_cycle_effect);
               break;
    }
     #endif // RGB_MATRIX_ENABLE
  return state;
}
// clang-format on

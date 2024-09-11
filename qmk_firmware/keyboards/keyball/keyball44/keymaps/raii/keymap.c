/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#define KC_J_AT KC_LBRC // JISキーボードでの@キー
#define KC_J_CC KC_EQL  // JISキーボードでの^キー
#define KC_J_BS KC_INT1 // JISキーボードでの右下の\キー
#define KC_J_YN KC_INT3 // JISキーボードでの右上の¥キー
#define KC_J_LB KC_RBRC // JISキーボードでの[キー
#define KC_J_RB KC_BSLS // JISキーボードでの]キー
#define KC_J_CL KC_QUOT // JISキーボードでの:キー
#define KC_HEN  KC_INT4 // 変換
#define KC_MHEN KC_INT5 // 無変換
#define KC_HNZN KC_GRV  // 半角/全角
#define KC_KANA KC_INT2 // かな

// Tap Danceの宣言
enum {
  TD_L2 = 0,
  TD_L4,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_J_AT  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_J_CC  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENT   ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_MINS  , KC_RSFT  ,
                          TD(TD_L4), KC_LGUI  ,LT(2,KC_MHEN),LT(3,KC_SPC),LT(4,KC_ESC),           ALT_T(KC_BSPC),CTL_T(KC_HEN)   , _______  , _______  , TD(TD_L2)
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    XXXXXXX  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                        KC_INS   , KC_HOME  , KC_UP    , KC_END   , KC_RALT  , KC_RCTL  ,
    _______  , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,                                        KC_PGUP  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_BTN5  , _______  ,
    _______  , KC_F11   , KC_F12   , KC_PSCR  , KC_SCRL  , KC_PAUS  ,                                        KC_PGDN  , KC_BTN4  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  ,
                          _______  , _______  , TG(2)    , _______  , _______  ,                  ALT_T(KC_DEL),_______          , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , S(KC_1)  , S(KC_6)  ,S(KC_J_YN), S(KC_7)  ,S(KC_J_LB),                                       S(KC_J_RB), S(KC_2)  ,S(KC_J_BS),S(KC_J_CL),S(KC_SLSH), S(KC_3)  ,
    _______  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                        KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    _______  , S(KC_4)  , S(KC_5)  , KC_J_YN  , S(KC_8)  , KC_J_LB  ,                                        KC_J_RB  , S(KC_9)  , KC_J_BS  , KC_J_CL  , KC_SLSH  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    KC_NUM   , KC_PSLS  , KC_P7    , KC_P8    , KC_P9    , KC_PMNS  ,                                        AML_TO   , AML_D50  , AML_I50  , SCRL_DVD , SCRL_DVI , KBC_SAVE ,
    _______  , KC_PAST  , KC_P4    , KC_P5    , KC_P6    , KC_PPLS  ,                                        RGB_TOG  , KC_HNZN  , KC_CAPS  , KC_KANA  , KC_APP   , _______  ,
    _______  , XXXXXXX  , KC_P1    , KC_P2    , KC_P3    , KC_PENT  ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , XXXXXXX  , _______  ,
                          KC_P0    , KC_PDOT  , _______  , _______  , TG(4)    ,                  _______  , _______             , _______  , _______  , KBC_RST
  ),

  [5] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),

  [6] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),

  [7] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),
};
// clang-format on

static bool scroll_pressed = false;

static void update_scroll_mode(layer_state_t state) {
  keyball_set_scroll_mode(scroll_pressed || get_highest_layer(state) == 4);
}

static void set_scroll_pressed(bool pressed) {
  scroll_pressed = pressed;
  update_scroll_mode(layer_state);
}

// レイヤーでのスクロールモード切り替えと色設定
layer_state_t layer_state_set_user(layer_state_t state) {
  update_scroll_mode(state);

  uint8_t layer = get_highest_layer(state);

  if (layer == 0) {
    rgblight_sethsv(0, 0, 48);
  } else {
    rgblight_sethsv((layer + 2) << 5, 255, 64);
  }

  return state;
}

// OLEDの設定
#ifdef OLED_ENABLE
#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}

// ファームウェアのサイズを削減するためロゴの代わりにテキストを表示
void oledkit_render_logo_user(void) {
  oled_write_P(PSTR(
    "\n"
    "      Keyball44\n"
    "    built by raii"
    ), false);
}
#endif

// Quick Tapの設定
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // 無変換・変換の場合はQuick Tapを無効化
    case LT(2, KC_MHEN):
    case LCTL_T(KC_HEN):
      return 0;

    // スペースの場合は誤入力を防ぐためQuick Tap Termを短くする
    case LT(3, KC_SPC):
      return 80;

    default:
      return TAPPING_TERM;
  }
}

// Tap Danceの設定
#ifdef TAP_DANCE_ENABLE
static void td_l2_finished(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    set_scroll_pressed(true);
  } else {
    layer_invert(2);
  }
}

static void td_l2_reset(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    set_scroll_pressed(false);
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_L2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l2_finished, td_l2_reset),
  [TD_L4] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_NO, 4),
};
#endif

// Comboの設定
#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_btn4[] = { KC_BTN1, KC_BTN2, COMBO_END };
const uint16_t PROGMEM combo_btn5[] = { KC_BTN2, KC_BTN3, COMBO_END };
combo_t key_combos[] = {
  COMBO(combo_btn4, KC_BTN4),
  COMBO(combo_btn5, KC_BTN5),
};
#endif

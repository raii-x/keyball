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
#include "keymap_japanese.h"

// レイヤーの定義
enum layers {
  _DEF, // Default
  _GAM, // Game
  _AMO, // Auto Mouse
  _F_M, // Function / Move
  _N_S, // Number / Symbol
  _P_A, // Pad / Adjust
};

// Tap Danceの宣言
enum {
  TD_F_M,
  TD_P_A,
};

// カスタムキーコードの宣言
enum custom_keycodes {
  CK_SCRL = SAFE_RANGE, // マウススクロール
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = LAYOUT_universal(
    JP_AT    , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , JP_CIRC  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     ,RSFT_T(KC_SCLN),KC_ENT,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_MINS  ,TD(TD_F_M),
                         TD(TD_P_A), KC_LGUI  ,LT(_F_M,JP_MHEN),LT(_N_S,KC_SPC),LT(_P_A,KC_ESC),  ALT_T(KC_BSPC),CTL_T(JP_HENK)  , _______  , _______  , CK_SCRL
  ),

  [_GAM] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    KC_LSFT  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENT   ,
    KC_LCTL  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                          TG(_GAM) , KC_LALT  , KC_SPC   , MO(_N_S) , KC_ESC ,                    MO(_F_M) , KC_RCTL             , _______  , _______  , KC_RALT
  ),

  [_AMO] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),

  [_F_M] = LAYOUT_universal(
    KC_PSCR  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                        KC_INS   , KC_HOME  , KC_UP    , KC_END   , KC_RALT  , KC_RCTL  ,
    _______  , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,                                        KC_PGUP  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_RSFT  , _______  ,
    _______  , KC_F11   , KC_F12   , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_PGDN  , KC_BTN4  , KC_BTN1  , KC_BTN2  , KC_BTN3  , KC_BTN5  ,
                          _______  , _______  , TG(_F_M) , _______  , _______  ,                  ALT_T(KC_DEL),_______          , _______  , _______  , _______
  ),

  [_N_S] = LAYOUT_universal(
    KC_CAPS  , S(KC_1)  , S(KC_6)  , S(JP_YEN), S(KC_7)  ,S(JP_LBRC),                                       S(JP_RBRC), S(KC_2)  ,S(JP_BSLS),S(JP_COLN),S(KC_SLSH), S(KC_3)  ,
    _______  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                        KC_6     , KC_7     , KC_8     , KC_9     ,RSFT_T(KC_0),_______ ,
    _______  , S(KC_4)  , S(KC_5)  , JP_YEN   , S(KC_8)  , JP_LBRC  ,                                        JP_RBRC  , S(KC_9)  , JP_BSLS  , JP_COLN  , KC_SLSH  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                  _______  , _______             , _______  , _______  , _______
  ),

  [_P_A] = LAYOUT_universal(
    KC_NUM   , KC_PSLS  , KC_P7    , KC_P8    , KC_P9    , KC_PMNS  ,                                        AML_TO   , AML_D50  , AML_I50  , SCRL_DVD , SCRL_DVI , KBC_SAVE ,
    KC_SCRL  , KC_PAST  , KC_P4    , KC_P5    , KC_P6    , KC_PPLS  ,                                        RGB_TOG  , TG(_GAM) , JP_ZKHK  , JP_KANA  , KC_APP   , SSNP_VRT ,
    KC_PAUS  , XXXXXXX  , KC_P1    , KC_P2    , KC_P3    , KC_PENT  ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , SSNP_HOR , SSNP_FRE ,
                          KC_P0    , KC_PDOT  , _______  , _______  , TG(_P_A) ,                  _______  , _______             , _______  , _______  , KBC_RST
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
  keyball_set_scroll_mode(scroll_pressed || get_highest_layer(state) == _P_A);
}

static void set_scroll_pressed(bool pressed) {
  scroll_pressed = pressed;
  update_scroll_mode(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  update_scroll_mode(state);

  // レイヤーに応じてRGBの色を変更
  uint8_t layer = get_highest_layer(state);

  if (layer == 0) {
    rgblight_sethsv(0, 0, 48);
  } else {
    rgblight_sethsv((layer + 1) << 5, 255, 64);
  }

  return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  return layer_state_set_user(state);
}

// カスタムキーコードの処理
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == CK_SCRL) {
      set_scroll_pressed(record->event.pressed);
  }

  return true;
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
    case LT(_F_M, JP_MHEN):
    case LCTL_T(JP_HENK):
      return 0;

    // スペースの場合は誤入力を防ぐためQuick Tap Termを短くする
    case LT(_N_S, KC_SPC):
      return 80;

    default:
      return TAPPING_TERM;
  }
}

// Tap Danceの設定
#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {
  [TD_F_M] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_NO, _F_M),
  [TD_P_A] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LCTL, _P_A),
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

// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define BACKLIGHT_DEFAULT_ON false
#define RGBLIGHT_DEFAULT_ON false

//#if CUSTOM_ENABLE_COMPOSITE_ACCENT
//  // the code that should be here is afters this comment because i don't know how to add custom configuration
//#else
//  #define CUSTOM_ENABLE_COMPOSITE_ACCENT_ENUM
//
//  #define CUSTOM_ENABLE_COMPOSITE_ACCENT_ACTION
//
//#endif

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
//#define UNICODE_KEY_LNX	LCTL(LSFT(KC_U))

#define CUSTOM_ENABLE_COMPOSITE_ACCENT_FUNCTION(NAME, KEY, UNICODE)       \
void NAME(tap_dance_state_t *state, void *user_data) {          \
  if (state->count == 1) {                                                \
    tap_code16(KEY);                                                      \
  }                                                                       \
  else if (state->count == 2) {                                           \
    register_unicode(UNICODE);                                            \
  }                                                                       \
}

#define CUSTOM_ENABLE_COMPOSITE_ACCENT_ENUM \
  TD_GRAVE_GRAVE,                           \
  TD_QUOTE_ACUTE,

#define CUSTOM_ENABLE_COMPOSITE_ACCENT_ACTION                       \
  [TD_GRAVE_GRAVE] = ACTION_TAP_DANCE_FN(c_td_fn_grave),            \
  [TD_QUOTE_ACUTE] = ACTION_TAP_DANCE_FN(c_td_fn_acute),

#define MIRYOKU_LAYER_BASE \
  KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              TD(TD_QUOTE_ACUTE),      \
  LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),        \
  LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
  U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
  KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
  KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
  TD(TD_GRAVE_GRAVE),    KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
  U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

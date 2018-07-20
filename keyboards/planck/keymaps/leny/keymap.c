/* Copyright 2017 Pierre-Antoine "Leny" Delnatte (from Jack Humbert)
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
    _REST,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum planck_keycodes {
    LN_CMSM,
    LN_DTCN,
    LN_SLQM,
    LN_CCED,
};

// --- Redefine KEYMAPS
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// ----- Default layer
#define LN_ESC KC_ESC
#define LN_A KC_Q
#define LN_Z KC_W
#define LN_E KC_E
#define LN_R KC_R
#define LN_T KC_T
#define LN_Y KC_Y
#define LN_U KC_U
#define LN_I KC_I
#define LN_O KC_O
#define LN_P KC_P
#define LN_BKSP KC_BSPC
#define LN_TAB KC_TAB
#define LN_Q KC_A
#define LN_S KC_S
#define LN_D KC_D
#define LN_F KC_F
#define LN_G KC_G
#define LN_H KC_H
#define LN_J KC_J
#define LN_K KC_K
#define LN_L KC_L
#define LN_M KC_SCLN
#define LN_ENTER KC_ENT
#define LN_LSFT KC_LSFT
#define LN_W KC_Z
#define LN_X KC_X
#define LN_C KC_C
#define LN_V KC_V
#define LN_B KC_B
#define LN_N KC_N
#define LN_RSFT KC_RSFT
#define LN_REKT KC_MEH
#define LN_LCTRL KC_RCTRL
#define LN_LALT KC_LALT
#define LN_META KC_LGUI
#define LN_SPACE KC_SPC
#define LN_LEFT KC_LEFT
#define LN_DOWN KC_DOWN
#define LN_UP KC_UP
#define LN_RIGHT KC_RIGHT
#define LN_EQPL KC_SLSH
#define LN_COMMA KC_M
#define LN_SEMICOLON KC_COMM
#define LN_DOT LSFT(KC_COMM)
#define LN_COLON KC_DOT
#define LN_SLASH LSFT(KC_DOT)
#define LN_QUESTION LSFT(KC_M)

// ----- Raise layer
#define LN_1 LSFT(KC_1)
#define LN_2 LSFT(KC_2)
#define LN_3 LSFT(KC_3)
#define LN_4 LSFT(KC_4)
#define LN_5 LSFT(KC_5)
#define LN_6 LSFT(KC_6)
#define LN_7 LSFT(KC_7)
#define LN_8 LSFT(KC_8)
#define LN_9 LSFT(KC_9)
#define LN_0 LSFT(KC_0)
#define LN_HASH LSFT(KC_NUBS)
#define LN_EURO LALT(KC_RBRC)
#define LN_SLASH LSFT(KC_DOT)
#define LN_LCHEV KC_GRV
#define LN_COPYR LALT(KC_C)
#define LN_LIGOE LALT(KC_O)
#define LN_LOWERCCED KC_9
#define LN_UPPERCCED LALT(KC_9)
#define LN_RCHEV LSFT(KC_GRV)
#define LN_PERCENT LSFT(KC_QUOT)
#define LN_ASTR LSFT(KC_RBRC)
#define LN_AT KC_NUBS
#define LN_POUND KC_PIPE
#define LN_ASLASH LALT(LSFT(KC_DOT))
#define LN_DLCHEV LALT(KC_7)
#define LN_INFINITE LALT(KC_M)
#define LN_LIGAE LALT(KC_Q)
#define LN_PI LALT(KC_P)
#define LN_DRCHEV LALT(KC_AMPR)
#define LN_CIRC KC_LBRC
#define LN_DOLLAR KC_RBRC
#define LN_HOME KC_HOME
#define LN_PGDWN KC_PGDN
#define LN_PGUP KC_PGUP
#define LN_END KC_END

// ----- Lower layer
#define LN_AMP KC_1
#define LN_EACUTE KC_2
#define LN_DBQUOTE KC_3
#define LN_LPAREN KC_5
#define LN_PGPH KC_6
#define LN_EAGRAVE KC_7
#define LN_EXLM KC_8
#define LN_DASH KC_EQL
#define LN_RPAREN KC_MINS
#define LN_GRAD LALT(KC_U)
#define LN_MIDDOT LALT(KC_NUBS)
#define LN_EACIRC LALT(KC_E)
#define LN_QUOTE KC_4
#define LN_LCURLY LALT(KC_5)
#define LN_TM LALT(LSFT(KC_T))
#define LN_AAGRAVE KC_0
#define LN_PIPE LALT(LSFT(KC_L))
#define LN_UNDSCR LSFT(KC_EQL)
#define LN_RCURLY LALT(KC_MINS)
#define LN_MU LALT(KC_SCLN)
#define LN_TRIDOT LALT(KC_COMM)
#define LN_AGRAVE KC_NUHS
#define LN_ACUTE LALT(KC_EXLM)
#define LN_LBRCK LALT(LSFT(KC_5))
#define LN_TILD LALT(KC_N)
#define LN_UAGRAVE KC_QUOT
#define LN_TREMA LSFT(KC_LBRC)
#define LN_PLMIN LALT(LSFT(KC_SLSH))
#define LN_NOTEQL LALT(KC_SLSH)
#define LN_RBRCK LALT(LSFT(KC_MINS))

const uint16_t PROGMEM keymaps[][ MATRIX_ROWS ][ MATRIX_COLS ] = {
    // REST (DEFAULT)
    [ _REST ] = LAYOUT_planck_grid(
        LN_ESC, LN_A, LN_Z, LN_E, LN_R, LN_T, LN_Y, LN_U, LN_I, LN_O, LN_P, LN_BKSP,
        LN_TAB, LN_Q, LN_S, LN_D, LN_F, LN_G, LN_H, LN_J, LN_K, LN_L, LN_M, LN_ENTER,
        LN_LSFT, LN_W, LN_X, LN_C, LN_V, LN_B, LN_N, LN_CMSM, LN_DTCN, LN_SLQM, LN_EQPL, LN_RSFT,
        LN_REKT, LN_LCTRL, LN_LALT, LN_META, LOWER, LN_SPACE, LN_SPACE, RAISE, LN_LEFT, LN_DOWN, LN_UP, LN_RIGHT
    ),
    // RAISE
    [ _RAISE ] = LAYOUT_planck_grid(
        _______, LN_1, LN_2, LN_3, LN_4, LN_5, LN_6, LN_7, LN_8, LN_9, LN_0, _______,
        _______, LN_HASH, LN_EURO, LN_SLASH, LN_LCHEV, LN_COPYR, LN_LIGOE, LN_CCED, LN_RCHEV, LN_PERCENT, LN_ASTR, _______,
        _______, LN_AT, LN_POUND, LN_ASLASH, LN_DLCHEV, LN_INFINITE, LN_LIGAE, LN_PI, LN_DRCHEV, LN_CIRC, LN_DOLLAR, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, LN_HOME, LN_PGDWN, LN_PGUP, LN_END
    ),
    // LOWER
    [ _LOWER ] = LAYOUT_planck_grid(
        _______, LN_AMP, LN_EACUTE, LN_DBQUOTE, LN_LPAREN, LN_PGPH, LN_EAGRAVE, LN_EXLM, LN_DASH, LN_RPAREN, LN_GRAD, KC_DEL,
        _______, LN_MIDDOT, LN_EACIRC, LN_QUOTE, LN_LCURLY, LN_TM, LN_AAGRAVE, LN_PIPE, LN_UNDSCR, LN_RCURLY, LN_TREMA, _______,
        _______, LN_TRIDOT, LN_ACUTE, LN_AGRAVE, LN_LBRCK, LN_TILD, LN_UAGRAVE, LN_PLMIN, LN_NOTEQL, LN_RBRCK, LN_MU, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    // ADJUST
    [ _ADJUST ] = LAYOUT_planck_grid(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, _______, RESET,
        _______, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, BL_STEP,
        _______, BL_DEC, BL_INC, _______, _______, _______, _______, _______, _______, KC__VOLDOWN, KC__VOLUP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MPLY, KC__MUTE, KC_MFFD
    )
};

// cf. https://github.com/fredizzimo/qmk_firmware/blob/fredizzimo_keymap/layouts/community/ergodox/fredizzimo/keymap.c#L136
void press_key_with_level_mods(uint16_t key) {
    const uint8_t interesting_mods = MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RALT);

    // Save the state
    const uint8_t real_mods = get_mods();
    const uint8_t weak_mods = get_weak_mods();
    const uint8_t macro_mods = get_macro_mods();

    uint8_t target_mods = (key >> 8) & (QK_MODS_MAX >> 8);
    // The 5th bit indicates that it's a right hand mod,
    // which needs some fixup
    if (target_mods & 0x10) {
        target_mods &= 0xF;
        target_mods <<= 4;
    }

    // Clear the mods that we are potentially going to modify,
    del_mods(interesting_mods);
    del_weak_mods(interesting_mods);
    del_macro_mods(interesting_mods);

    // Enable the mods that we need
    add_mods(target_mods & interesting_mods);

    // Press and release the key
    register_code(key & 0xFF);
    unregister_code(key & 0xFF);

    // Restore the previous state
    set_mods(real_mods);
    set_weak_mods(weak_mods);
    set_macro_mods(macro_mods);
    send_keyboard_report();
}

bool override_key(keyrecord_t* record, uint16_t normal, uint16_t shifted) {
    const uint8_t shift = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);

    uint8_t current_mods = get_mods();

    if (record->event.pressed) {
        bool shift_pressed = current_mods & shift;
        const uint16_t target = shift_pressed ? shifted : normal;
        uint8_t keycode = target & 0xFF;
        if (keycode == KC_NO) {
            return false;
        }
        press_key_with_level_mods(target);
    }
    return false;
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // KEYS
    case LN_CMSM:
        return override_key(record, LN_COMMA, LN_SEMICOLON);
        break;
    case LN_DTCN:
        return override_key(record, LN_DOT, LN_COLON);
        break;
    case LN_SLQM:
        return override_key(record, LN_SLASH, LN_QUESTION);
        break;
    case LN_CCED:
        return override_key(record, LN_LOWERCCED, LN_UPPERCCED);
        break;
  }
  return true;
}

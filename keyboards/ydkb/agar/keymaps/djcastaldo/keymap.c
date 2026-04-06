/* Copyright 2020 hineybush

 */
#include QMK_KEYBOARD_H

#include QMK_KEYBOARD_H
#include "layers.h"
#include "keyindex.h"
#include "process_record_userspace.h"

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__ ((weak))
bool process_leader_secrets(void) {
    return true;
}

// custom keycodes
enum custom_keycodes {
    CUSTOM_KEYCODE = USERSPACE_END,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAC_BASE] = LAYOUT_60_tsangan_hhkb(
        DUAL_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, LT(EMO_LAYR,KC_GRV),
        LT(TMUX_LAYR,KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BSPCFAST,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_TD, OSL_FKEY,
        _______, KC_LOPT, KC_LCMD, KC_SPC,  TD(RCMD_OSL), SP_RCTL, _______
    ),

    [WIN_BASE] = LAYOUT_60_tsangan_hhkb(
        DUAL_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, DYN_LT,
        LT(TMUX_LAYR,KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BSPCFAST,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_TD, OSL_FKEY,
        _______, TD(LGUI_OSL), KC_LALT, KC_SPC,  TD(RALT_OSL), SP_RCTL, _______
    ),

    [FKEY_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_HOME, KC_END, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, _______, _______,   _______, _______, _______, _______, _______,  _______, KC_PGDN, DUAL_SNAP, _______, _______,
        _______, _______, _______, _______, AP_GLOB, _______, _______
    ),

    [FN_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, VI_REPLACE, _______, GIT_CHKOUT, _______, GIT_LOG, GIT_ADD, GIT_COMMIT, GIT_PUSH, ARROW, WAVE, KC_SCRL, VSEMOLR,
        MO(TMUX_LAYR), SECRET3, SECRET2, SECRET1, SECRET8, SECRET9, _______, _______, _______, _______, _______, DM_REC1, DM_REC2, _______,
        _______, SECRET4, SECRET5, SECRET6, SECRET7, _______, _______, _______, _______, KC_LEAD,  _______, _______, _______,
        MO(SFT_LAYR), _______, SECRET10, SECRET11, SECRET12, SECRET13, GNEWS, _______, DM_PLY1, DM_PLY2, KC_PAUS, MO(SFT_LAYR), _______,
        _______, WM_SYM, MO(KCTL_LAYR), _______, MO(KCTL_LAYR), _______, _______
    ),

//137   [SFT_LAYR] = LAYOUT_hot(
//138    WM_QUIT,WM_SOC1,WM_SOC2,WM_SOC3,WM_SOC4,WM_SOC5,WM_SOC6,WM_SOC7,WM_SOC8,WM_SOC9,WM_SOC0,KC_VOLD,KC_VOLU,KC_NUM,WM_OVIEW, LLOCK,
//139    KC_APP,WM_QLOOK,WM_INSPECT,WM_VHIDDEN,_______, WM_TIME, _______,KC_P7,KC_P8,KC_P9,DUAL_PLUSMIN,CURSORL,CURSORR,_______,KC_CALC,
//140    _______, WM_APPS, WM_SIRCAT, WM_DOCS, WM_MYCM, KC_MYCM, _______, KC_P4, KC_P5, KC_P6, DUAL_MULTDIV, _______, _______,  MK_HOLD,
//141    _______, MK_ACCEL2, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_P1, KC_P2, KC_P3,WM_STATB,KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,
//142    _______, _______, MK_ACCEL0,                  KC_P0,                    KC_PDOT, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT),
    [SFT_LAYR] = LAYOUT_60_tsangan_hhkb(
        WM_QUIT,  WM_SOC1,  WM_SOC2,  WM_SOC3, WM_SOC4, WM_SOC5, WM_SOC6, WM_SOC7, WM_SOC8, WM_SOC9, WM_SOC0, KC_VOLD, KC_VOLU, KC_NUM, WM_OVIEW,
        KC_APP, WM_QLOOK, WM_INSPECT, WM_VHIDDEN, _______,  WM_TIME, _______, KC_P7, KC_P8, KC_P9, DUAL_PLUSMIN, CURSORL, CURSORR, _______,
        _______, WM_APPS, WM_SIRCAT, WM_DOCS, WM_MYCM, KC_MYCM, _______,    KC_P4, KC_P5, KC_P6, DUAL_MULTDIV, _______, _______,
        _______, MK_ACCEL2, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,  KC_P1, KC_P2, KC_P3, WM_STATB, _______, _______,
        _______, _______, MK_ACCEL0, KC_P0,  KC_PDOT, _______, _______
    ),

    [KCTL_LAYR] = LAYOUT_60_tsangan_hhkb(
        ENC_RGBPUSH, _______, _______, _______, _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______, _______, DB_TOGG, _______, SECRET0,
        _______, _______, _______, _______, QK_RBT, _______, _______,  _______, _______, RGB_MOD, _______,   RGB_SPD, RGB_SPI, CSTMTOG,
        _______, _______, _______, _______, FLASH_KB, _______, _______, _______, KC_LOCK,   _______, _______, _______, _______,
        _______, _______, _______,   EE_CLR, _______, BOOTLDR, _______, _______,  _______, RGB_RMOD, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),

    [TMUX_LAYR] = LAYOUT_60_tsangan_hhkb(
        TMUXLKEY, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, TWINLFT, TWINRGT,
        _______, LTRANS, LTRANS, _______, _______, LTRANS, _______, _______, _______, LTRANS, LTRANS, LTRANS, LTRANS, TMUXLCMD,
        _______, _______, LTRANS, LTRANS, _______, _______, _______, TJPANE, _______, LTRANS, LTRANS, LTRANS, _______,
        _______, LTRANS, LTRANS, LTRANS, _______, _______, LTRANS, ENC_TMON, LTRANS, LTRANS, LTRANS, _______, MO(TMUX_LAYR_NAV),
        _______, KC_LALT, KC_LALT, LTRANS, KC_LALT, _______, _______
    ),
    [TMUX_LAYR_NAV] = LAYOUT_60_tsangan_hhkb(
        TMUXLKEY, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, TWINLFT, TWINRGT,
        _______, LTRANS, LTRANS, _______, _______, LTRANS, _______, _______, _______, TKC_PGUP, TKC_UP, LTRANS, LTRANS, TMUXLCMD,
        _______, _______, LTRANS, LTRANS, _______, _______, _______, TJPANE, _______, TKC_LEFT, TKC_DOWN, TKC_RGHT, _______,
        _______, LTRANS, LTRANS, LTRANS, _______, _______, LTRANS, ENC_TMON, LTRANS, KC_PGDN, LTRANS, _______, _______,
        _______, KC_LALT, KC_LALT, LTRANS, KC_LALT, _______, _______
    ),

    [VS_LAYR] = LAYOUT_60_tsangan_hhkb(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______,
        _______, KC_LGUI, KC_LALT, KC_SPC,  KC_RALT, KC_RGUI, _______
    ),

    [MSYM_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),

    [WSYM_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),
    [WIDE_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, KC_DEL,
        KC_CAPS, _______,  _______,  _______,  _______,  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______, _______,
        _______, _______,  _______,  _______,  _______,  _______, _______, KC_MUTE, _______, _______, _______, KC_MPLY, _______,
        _______, _______, _______, KC_MPLY, _______, _______, _______
    ),
    [CIRC_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),
    [EMO_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, KC_DEL,
        KC_CAPS, _______,  _______,  _______,  _______,  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______, _______,
        _______, _______,  _______,  _______,  _______,  _______, _______, KC_MUTE, _______, _______, _______, KC_MPLY, _______,
        _______, _______, _______, KC_MPLY, _______, _______, _______
    ),
    [LOCK_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),

    /* [_RAISE] = LAYOUT_60_tsangan_hhkb( */
    /*     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, */
    /*     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL, */
    /*     KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, */
    /*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
    /*     _______, _______, _______, _______, _______, _______, _______ */
    /* ), */


    /* [_MOUSE] = LAYOUT_60_tsangan_hhkb( */
    /*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
    /*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
    /*     _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, */
    /*     _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______, _______, _______, _______, */
    /*     _______, _______, _______, KC_BTN1, _______, _______, _______ */
    /* ), */


};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // userspace
    if (!process_record_userspace(keycode,record)) {
        return false;
    }
    // secrets
    return process_record_secrets(keycode, record);
}

void leader_end_user(void) {
    uprintf("\n\n[LEADER] >>> leader_end_user CALLED <<<\n\n");
    // if either userspace or secrets return false, leader matching stops there
    if (process_leader_userspace() && process_leader_secrets()) {
        // leader sequence failed, so blink the rgb red a few times
        is_leader_error = true;
        leader_error_token = defer_exec(1500, leader_error_callback, NULL);  // schedule callback
    }

    is_in_leader_sequence = false;
}

void leader_end(void) {
    leader_end_user();
}

uint16_t get_dyn_ltkey(void) {
    return KC_GRV;
}
// which led index is under the DYN_LT key?
uint16_t get_dyn_ltindex(void) {
    return 0;
}

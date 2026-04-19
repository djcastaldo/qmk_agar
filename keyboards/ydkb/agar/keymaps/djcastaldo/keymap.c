/* Dave Castaldo @davex 
   06 APR 2026 
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
void enter_bootloader(void);

// custom keycodes
enum custom_keycodes {
    AGARBOOT = USERSPACE_END,
    AGARCOMPILE,
    AGARFLASH
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAC_BASE] = LAYOUT_60_tsangan_hhkb(
        DUAL_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, DYN_LT,
        TMUX_LT,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BSPCFAST,
        FN_HHKB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_TD, OSL_FKEY,
        _______, KC_LOPT, KC_LCMD, KC_SPC,  RCMD_TD, SP_RCTL, _______
    ),

    [WIN_BASE] = LAYOUT_60_tsangan_hhkb(
        DUAL_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, DYN_LT,
        TMUX_LT, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BSPCFAST,
        FN_HHKB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_TD, OSL_FKEY,
        _______, TD(LGUI_OSL), KC_LALT, KC_SPC,  RALT_TD, SP_RCTL, _______
    ),

    [FKEY_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_HOME, KC_END, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, _______, _______,   _______, _______, _______, _______, _______,  KC_PGUP, KC_PGDN, DUAL_SNAP, _______, _______,
        _______, _______, _______, _______, AP_GLOB, _______, _______
    ),

    [FN_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______,_______,_______,VI_REPLACE,_______,GIT_CHKOUT,_______,GIT_LOG,GIT_ADD,GIT_COMMIT,GIT_PUSH, ARROW, WAVE, KC_SCRL, VSEMOLR,
        MO(TMUX_LAYR), SECRET3, SECRET2, SECRET1, SECRET8, SECRET9, _______,_______,_______, _______, _______, DM_REC1, DM_REC2, _______,
        _______, SECRET4, SECRET5, SECRET6, SECRET7, _______, _______, _______, _______, KC_LEAD,  _______, _______, _______,
        MO(SFT_LAYR), _______, SECRET10, SECRET11, SECRET12, SECRET13, GNEWS, _______, DM_PLY1, DM_PLY2, KC_PAUS, MO(SFT_LAYR), _______,
        _______, WM_SYM, MO(KCTL_LAYR), _______, MO(KCTL_LAYR), _______, _______
    ),

    [SFT_LAYR] = LAYOUT_60_tsangan_hhkb(
        WM_QUIT, WM_SOC1, WM_SOC2, WM_SOC3, WM_SOC4, WM_SOC5, WM_SOC6, WM_SOC7, WM_SOC8, WM_SOC9, WM_SOC0,KC_VOLD,KC_VOLU,KC_NUM, WM_OVIEW,
        KC_APP, WM_QLOOK, WM_INSPECT, WM_VHIDDEN, _______,  WM_TIME, _______, _______, KC_P7, KC_P8, KC_P9, DUAL_PLUSMIN, CURSORR, _______,
        MO(FKEY_LAYR), WM_APPS, WM_SIRCAT, WM_DOCS, WM_MYCM, KC_MYCM, _______,    _______, KC_P4, KC_P5, KC_P6, DUAL_MULTDIV, _______,
        _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,  WM_STATB, KC_P1, KC_P2, KC_P3, _______, MO(FKEY_LAYR),
        _______, _______, _______, KC_P0,  KC_PDOT, _______, _______
    ),
    [SFT_LAYR_NAV] = LAYOUT_60_tsangan_hhkb(
        WM_QUIT, WM_SOC1, WM_SOC2, WM_SOC3, WM_SOC4, WM_SOC5, WM_SOC6, WM_SOC7, WM_SOC8, WM_SOC9, WM_SOC0,KC_MUTE,KC_MUTE,KC_NUM, WM_OVIEW,
        KC_APP, WM_QLOOK, WM_INSPECT, WM_VHIDDEN, _______,  WM_TIME, _______,KC_NO,CURSORL,KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, CURSORR,_______,
        _______, WM_APPS, WM_SIRCAT, WM_DOCS, WM_MYCM, KC_MYCM, _______,    KC_NO, KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,
        _______, MK_ACCEL2, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,  KC_NO, KC_NO, MK_HOLD, KC_CALC, _______, _______,
        _______, _______, MK_ACCEL0, KC_NO,  KC_NO, _______, _______
    ),

    [KCTL_LAYR] = LAYOUT_60_tsangan_hhkb(
        ENC_RGBPUSH, RGB_VAD,RGB_VAI,_______,_______,RGB_HUD,RGB_HUI,RGB_SAD,RGB_SAI, _______, _______, _______, DB_TOGG, _______, SECRET0,
        _______, _______, _______, _______, QK_RBT, _______, _______,  _______, _______, RGB_MOD, _______,   RGB_SPD, RGB_SPI, CSTMTOG,
        _______, _______, _______, AGARCOMPILE, AGARFLASH, _______, _______, _______, KC_LOCK,   _______, _______, _______, _______,
        _______, _______, _______,   EE_CLR, _______, AGARBOOT, _______, _______,  _______, RGB_RMOD, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),

    [TMUX_LAYR] = LAYOUT_60_tsangan_hhkb(
        TMUXLKEY, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, TWINLFT, TWINRGT,
        _______, LTRANS, LTRANS, _______, _______, LTRANS, _______, _______, _______, LTRANS, LTRANS, LTRANS, LTRANS, TMUXLCMD,
        MO(FKEY_LAYR), _______, LTRANS, LTRANS, _______, _______, _______, TJPANE, _______, LTRANS, LTRANS, LTRANS, _______,
        _______, LTRANS, LTRANS, LTRANS, _______, _______, LTRANS, ENC_TMON, LTRANS, LTRANS, LTRANS, _______, MO(FKEY_LAYR),
        _______, KC_LALT, KC_LALT, LTRANS, KC_LALT, _______, _______
    ),
    [TMUX_LAYR_NAV] = LAYOUT_60_tsangan_hhkb(
        TMUXLKEY, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, TWINLFT, TWINRGT,
        _______, LTRANS, LTRANS, _______, _______, LTRANS, _______, _______, _______, LTRANS, TKC_UP, LTRANS, LTRANS, TMUXLCMD,
        _______, _______, LTRANS, LTRANS, _______, _______, _______, TJPANE, _______, TKC_LEFT, TKC_DOWN, TKC_RGHT, _______,
        _______, LTRANS, LTRANS, LTRANS, _______, _______, LTRANS, ENC_TMON, TKC_PGUP, KC_PGDN, LTRANS, _______, _______,
        _______, KC_LALT, KC_LALT, LTRANS, KC_LALT, _______, _______
    ),

    [VS_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______,  KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, VSINSLN, _______,
        _______, _______, VSWRDWP, VSERR, VSRNAME, _______, _______, VSLNCMU, VSINFO, VSOUTPT, VSPUB, VSMVLNU, VSMATCH, VSDELLN,
        _______, _______, VSLNSRT, VSDUPLN, VSFIND, VSGOTO, VSREPL, VSLJOIN, _______, VSSOLU, _______, VSMVLND, _______,
        _______, _______, _______, VSLNCMC, VSCLIPB, _______, VSNOTIF, _______, _______, _______, VSLBCMT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),

    [MSYM_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, KC_GRV,
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, _______,
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, _______,
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, NBSP, _______,
        _______, _______, TD(SUIT_CYCLE), _______, TD(SUP_CYCLE), _______, _______
    ),

    [WSYM_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, TD(ACT_1), OPT2, OPT3, OPT4, OPT5, OPT6, OPT7, OPT8, OPT9, OPT0, OPTMIN, OPTEQ, OPTBSL, TD(ACT_GRV),
        _______, OPTQ, OPTW, TD(ACT_E), OPTR, OPTT, OPTY, TD(ACT_U), TD(ACT_I), OPTO, OPTP, OPTLBR, OPTRBR, _______,
        _______, OPTA, OPTS, OPTD, OPTF, OPTG, OPTH, OPTJ, OPTK, OPTL,  OPTSEM, OPTAPO, _______,
        _______, OPTZ, OPTX, OPTC, OPTV, OPTB, TD(ACT_N), OPTM, OPTCOM, OPTDOT, OPTSLS, NBSP, _______,
        _______, _______, TD(SUIT_CYCLE), _______, TD(SUP_CYCLE), _______, _______
    ),

    [WIDE_LAYR] = LAYOUT_60_tsangan_hhkb(
        BBRTEXT, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS,
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS,   LTRANS, _______,
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, _______,
        _______, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, LTRANS, _______, _______,
        _______, BARTEXT, UNDERLN, LTRANS, STHRU, _______, _______
    ),

    [CIRC_LAYR] = LAYOUT_60_tsangan_hhkb(
        _______, CIRCL1, CIRCL2, CIRCL3, CIRCL4, CIRCL5, CIRCL6, CIRCL7, CIRCL8, CIRCL9, CIRCL0, _______, _______, _______, _______,
        _______,  CIRCLQ, CIRCLW, CIRCLE, CIRCLR, CIRCLT, CIRCLY, CIRCLU, CIRCLI, CIRCLO, CIRCLP, _______, _______, _______,
        _______, CIRCLA, CIRCLS, CIRCLD, CIRCLF, CIRCLG, CIRCLH, CIRCLJ, CIRCLK, CIRCLL, _______, _______, _______,
        _______, CIRCLZ, CIRCLX, CIRCLC, CIRCLV, CIRCLB, CIRCLN, CIRCLM, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),

    [EMO_LAYR] = LAYOUT_60_tsangan_hhkb(
        E_EMARK, E_K1, E_K2, E_K3, E_K4, E_K5, E_K6, E_K7, E_K8, E_K9, E_K0, E_MINS, E_PLUS, E_SMILE, _______,
        E_SAD, E_PIZZA, E_BURGER, E_CHICKEN, E_TACO, E_TRASH, E_BULB, E_SMIRK, E_I, E_OK, E_PACKAGE, E_FLAGUS, E_FLAGPI, _______,
        _______, E_STAR,  E_SGLASS,  E_DRINK,  E_SSHOT,  E_GLOBE, E_HASH, E_CMARK, E_KB, E_SNAIL, E_STOP, E_HAND, _______,
        _______, E_BUS,  E_TRAIN,  E_CAR,  E_TAXI,  E_BOTTLE, E_NINJA, E_MIC, E_SHH, E_GRIM, E_DIV, _______, E_QMARK,
        _______, E_POINTL, E_POINTD, _______, E_POINTU, E_POINTR, _______
    ),

    [LOCK_LAYR] = LAYOUT_60_tsangan_hhkb(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TD(KB_UNLOCK),
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

};
// clang-format on

static uint32_t agarboot_key_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // userspace
    if (!process_record_userspace(keycode,record)) {
        return false;
    }
    switch (keycode) {
        case AGARBOOT:
            if (record->event.pressed) {
                agarboot_key_timer = timer_read32();
            } else if (timer_elapsed32(agarboot_key_timer) >= 500) {
                enter_bootloader();
            }
            return false;
        case AGARCOMPILE:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -j 0 -kb ydkb/agar -km djcastaldo\n");
            }
            return false;
        case AGARFLASH:
            if (record->event.pressed) {
                SEND_STRING("cd ~/qmk_public/agar\n./bin2uf2.sh ydkb_agar_djcastaldo.bin\n");
            }
            return false;
    }
    // secrets
    return process_record_secrets(keycode, record);
}

void leader_end_user(void) {
    dprintf("\n\n[LEADER] >>> leader_end_user CALLED <<<\n\n");
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

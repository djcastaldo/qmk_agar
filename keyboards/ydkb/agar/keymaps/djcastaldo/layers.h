// @djcastaldo 08-01-2025
// setup to access layers from outside keymap
#pragma once

enum layers {
    MAC_BASE,
    WIN_BASE,
    FKEY_LAYR,
    FN_LAYR,
    SFT_LAYR,
    SFT_LAYR_NAV,
    KCTL_LAYR,
    TMUX_LAYR,
    TMUX_LAYR_NAV,
    VS_LAYR,
    MSYM_LAYR,
    WSYM_LAYR,
    WIDE_LAYR,
    CIRC_LAYR,
    EMO_LAYR,
    LOCK_LAYR
};

#define SFT_TRILAYER
#define SFT_LOWER FKEY_LAYR
#define SFT_UPPER SFT_LAYR
#define SFT_ADJUST SFT_LAYR_NAV
#define TMUX_TRILAYER
#define TMUX_LOWER FKEY_LAYR
#define TMUX_UPPER TMUX_LAYR
#define TMUX_ADJUST TMUX_LAYR_NAV

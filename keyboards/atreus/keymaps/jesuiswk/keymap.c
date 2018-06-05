// This is the personal keymap of Jeremy Cowgar (@jcowgar). It is written for the programmer.

#include "atreus.h"
#include "action_layer.h"
#include "keymap_colemak.h"

#define PREVENT_STUCK_MODIFIERS
// Undefine if you use QWERTY
/*#define SOFTWARE_COLEMAK*/

// Reduce the time to decision of a tap or hold
#define TAPPING_TERM 50

// Each layer gets a name for readability, which is then used in the keymap matrix below.
#define BOOT  0 // Bootloader (not to be confused with default layer)
#define ALPH  0 // Alphabet Layer
#define NUMS  1 // Number Layer
#define FKEY  2 // Function Key Layer
#define CURS  3 // Cursor Layer
#define SYMB  4 // Symbol Layer
#define WINBS  5 // Option or Backspace
#define ALTDL  6 // Command or Delete
#define SFSP  7 // Left Shift or Space
#define SFET  8 // Right Shift or Enter
#define CTTB  9 // Control or Tab
#define CTES 10 // Control or Escape

#define FN_NUMS (KC_FN0 + NUMS)
#define FN_FKEY (KC_FN0 + FKEY)
#define FN_CURS (KC_FN0 + CURS)
#define FN_SYMB (KC_FN0 + SYMB)
#define FN_WINBS (KC_FN0 + WINBS)
#define FN_ALTDL (KC_FN0 + ALTDL)
#define FN_SFSP (KC_FN0 + SFSP)
#define FN_SFET (KC_FN0 + SFET)
#define FN_CTTB (KC_FN0 + CTTB)
#define FN_CTES (KC_FN0 + CTES)

#ifdef SOFTWARE_COLEMAK
  // Colemak defined in software is playing games with me
  #define KEY_SAVE KC_D
  #define KEY_CLSE KC_W
  #define KEY_OPEN KC_SCLN
  #define MY_SCLN  KC_P
#else
  #define KEY_SAVE KC_S
  #define KEY_CLSE KC_W
  #define KEY_OPEN KC_O
  #define MY_SCLN  KC_SCLN
#endif

// Some handy macros to keep the keymaps clean and easier to maintain
#define KM_SAVE LGUI(CM_S)
#define KM_CLSE LGUI(CM_W)
#define KM_OPEN LGUI(CM_O)

#define KM_COPY LGUI(KC_C)
#define KM_CUT  LGUI(KC_X)
#define KM_PAST LGUI(KC_V)
#define KM_UNDO LGUI(KC_Z)
#define KM_REDO LGUI(LSFT(KC_Z))

// Helpers for my symbol layer
/*#define KC_EXLM ACTION_MODS_KEY(MOD_LSFT, KC_1)*/
/*#define KC_AT   ACTION_MODS_KEY(MOD_LSFT, KC_2)*/
/*#define KC_HASH ACTION_MODS_KEY(MOD_LSFT, KC_3)*/
/*#define KC_DLR  ACTION_MODS_KEY(MOD_LSFT, KC_4)*/
/*#define KC_PERC ACTION_MODS_KEY(MOD_LSFT, KC_5)*/
/*#define KC_CIRC ACTION_MODS_KEY(MOD_LSFT, KC_6)*/
/*#define KC_AMPR ACTION_MODS_KEY(MOD_LSFT, KC_7)*/
/*#define KC_ASTR ACTION_MODS_KEY(MOD_LSFT, KC_8)*/
/*#define KC_LPRN ACTION_MODS_KEY(MOD_LSFT, KC_9)*/
/*#define KC_RPRN ACTION_MODS_KEY(MOD_LSFT, KC_0)*/
/*#define KC_UNDS ACTION_MODS_KEY(MOD_LSFT, KC_MINUS)*/
/*#define KC_PLUS ACTION_MODS_KEY(MOD_LSFT, KC_EQL)*/
#define MY_COLN ACTION_MODS_KEY(MOD_LSFT, MY_SCLN)
/*#define KC_QUES ACTION_MODS_KEY(MOD_LSFT, KC_SLSH)*/
/*#define KC_TILD ACTION_MODS_KEY(MOD_LSFT, KC_GRV)*/
/*#define KC_PIPE ACTION_MODS_KEY(MOD_LSFT, KC_BSLS)*/
/*#define KC_LCBR ACTION_MODS_KEY(MOD_LSFT, KC_LBRC)*/
/*#define KC_RCBR ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)*/
/*#define KC_DQT  ACTION_MODS_KEY(MOD_LSFT, KC_QUOT)*/
/*#define KC_LABK ACTION_MODS_KEY(MOD_LSFT, KC_COMM)*/
/*#define KC_RABK ACTION_MODS_KEY(MOD_LSFT, KC_DOT)*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = {
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  {KC_A,    FN_NUMS, FN_FKEY, KC_F,    KC_G,    KC_TRNS, KC_H,    KC_J,    FN_CURS, FN_SYMB, KC_SCLN},
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    FN_WINBS,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {FN_CTES, KC_TAB,  KC_GRV,  KC_LGUI, FN_SFET, FN_ALTDL,FN_SFSP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[NUMS] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_SLSH, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_SLSH},
  {KC_TRNS, KC_TRNS, KC_EQL,  KC_PLUS, KC_MINS, KC_TRNS, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR},
  {KC_TRNS, KC_TRNS, KC_DOT,  KC_COMM, KC_SCLN, KC_TRNS, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_DOT,  KC_EQL,  KC_PLUS}
},
[FKEY] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[CURS] = {
  {KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2,  KC_PGUP, KC_TRNS, KC_TRNS, KM_SAVE, KC_TRNS, KM_OPEN, KC_TRNS},
  {KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN, KC_TRNS, KM_UNDO, KC_LALT, KC_TRNS, KC_LGUI, KC_TRNS},
  {KC_VOLD, KC_MUTE, KC_VOLU, KC_MPLY, KC_MFFD, KM_COPY, KM_REDO, KM_CLSE, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TAB,  KM_CUT,  KM_PAST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[SYMB] = {
  {KC_BSLS, KC_EXLM, KC_LABK, KC_RABK, MY_COLN, KC_TRNS, KC_UNDS, KC_DLR,  KC_QUES, KC_TRNS, KC_PERC},
  {KC_AT,   KC_AMPR, KC_LPRN, KC_RPRN, MY_SCLN, KC_TRNS, KC_COMM, KC_DOT,  KC_QUOT, KC_TRNS, KC_TILD},
  {KC_HASH, KC_PIPE, KC_LCBR, KC_RCBR, KC_SLSH, KC_TRNS, KC_TRNS, KC_GRV,  KC_DQT,  KC_TRNS, KC_CIRC},
  {KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
}};

const uint16_t PROGMEM fn_actions[] = {
  [NUMS] = ACTION_LAYER_TAP_KEY(NUMS, KC_S),
  [FKEY] = ACTION_LAYER_TAP_KEY(FKEY, KC_D),
  [CURS] = ACTION_LAYER_TAP_KEY(CURS, KC_K),
  [SYMB] = ACTION_LAYER_TAP_KEY(SYMB, KC_L),
  [WINBS] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),
  [ALTDL] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_BSPC),
  [SFSP] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),
  [SFET] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
  [CTTB] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB),
  [CTES] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {}

  return MACRO_NONE;
};

.nds
.thumb

// Borrowed from Drayanos Aurora Crystal
// Edits the palettes of modified TMs
// All Credit to Drayano

.open "base/arm9.bin", 0x02000000

PALETTE_FIGHTING equ 398
PALETTE_DRAGON equ 399
PALETTE_WATER equ 400
PALETTE_PSYCHIC equ 401
PALETTE_NORMAL equ 402
PALETTE_POISON equ 403
PALETTE_ICE equ 404
PALETTE_GRASS equ 405
PALETTE_FIRE equ 406
PALETTE_DARK equ 407
PALETTE_STEEL equ 408
PALETTE_ELECTRIC equ 409
PALETTE_GROUND equ 410
PALETTE_GHOST equ 411
PALETTE_ROCK equ 412
PALETTE_FLYING equ 413
PALETTE_BUG equ 610

// Start of TM Palette Table
.org 0x02100BD6

// Between each TM we need to skip 8 * (TM gap - 1) bytes

// Keep TM01 Fighting palette
.skip 2
.halfword PALETTE_FIGHTING
.skip 4

// Change TM20 to Electric palette
.skip (8 * 18)
.skip 2
.halfword PALETTE_ELECTRIC
.skip 4

// Change TM21 to Ice palette
.skip 2
.halfword PALETTE_ICE
.skip 4

// Change TM32 to Water palette
.skip (8 * 10)
.skip 2
.halfword PALETTE_WATER
.skip 4

// Change TM43 to Psychic palette (Do not have Fairy)
.skip (8 * 10)
.skip 2
.halfword PALETTE_PSYCHIC
.skip 4

// Change TM49 to Psychic palette (Do not have Fairy)
.skip (8 * 5)
.skip 2
.halfword PALETTE_PSYCHIC
.skip 4

// Change TM56 to Psychic palette (Do not have Fairy)
.skip (8 * 6)
.skip 2
.halfword PALETTE_PSYCHIC
.skip 4

.close

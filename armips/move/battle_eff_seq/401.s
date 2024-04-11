.nds
.thumb

.include "armips/include/battlescriptcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/itemnums.s"
.include "armips/include/monnums.s"
.include "armips/include/movenums.s"

.create "build/move/battle_eff_seq/0_401", 0

//Heal Pulse

a030_401:
    changevar VAR_OP_SET, VAR_ADD_STATUS1, 0x80000042
    endscript

.close

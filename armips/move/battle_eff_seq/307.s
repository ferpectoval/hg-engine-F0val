.nds
.thumb

.include "armips/include/battlescriptcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/itemnums.s"
.include "armips/include/monnums.s"
.include "armips/include/movenums.s"

.create "build/move/battle_eff_seq/0_307", 0


//Wildfire
a030_307:
	changevar VAR_OP_SET, VAR_ADD_STATUS1,  ADD_STATUS_WILDFIRE | ADD_STATUS_ATTACKER
    critcalc
    damagecalc
	endscript

.close
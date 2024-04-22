.nds
.thumb

.include "armips/include/battlescriptcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/itemnums.s"
.include "armips/include/monnums.s"
.include "armips/include/movenums.s"

.create "build/move/battle_eff_seq/0_309", 0


//Freeze-Dry

a030_309:
    ifmonstat IF_NOTMASK, BATTLER_DEFENDER, MON_DATA_TYPE_2, 0x0B , a045_309
    changevar VAR_OP_SET, VAR_DAMAGE_MULT, 40
a045_309:
    ifmonstat IF_NOTMASK, BATTLER_DEFENDER, MON_DATA_TYPE_1, 0x0B , a060_309
    changevar VAR_OP_SET, VAR_DAMAGE_MULT, 40
a060_309:
    critcalc
    damagecalc
    endscript

.close
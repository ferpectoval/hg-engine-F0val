#include "../include/types.h"
#include "../include/script.h"
#include "../include/repel.h"
#include "../include/constants/file.h"
#include "../include/constants/item.h"

#define SCRIPT_NEW_CMD_REPEL_USE    0
#define SCRIPT_NEW_MARTS			1
#define SCRIPT_BERRY_MARTS			2
#define SCRIPT_TM_MARTS			    3
#define SCRIPT_TM_MART_ALL		    4
#define SCRIPT_OLIVINE_MARTS		5
#define SCRIPT_MEGA_MART			99
#define SCRIPT_RESET_MART			255
#define SCRIPT_NEW_CMD_MAX          256



u16 ALIGN4 NewMarts[][24] = 
{
	{ITEM_SILVER_POWDER, ITEM_METAL_COAT, ITEM_SOFT_SAND, ITEM_HARD_STONE, ITEM_MIRACLE_SEED, ITEM_BLACK_GLASSES, ITEM_BLACK_BELT, ITEM_MAGNET, ITEM_MYSTIC_WATER, ITEM_SHARP_BEAK, ITEM_POISON_BARB, ITEM_NEVER_MELT_ICE, ITEM_SPELL_TAG, ITEM_TWISTED_SPOON, ITEM_CHARCOAL, ITEM_DRAGON_FANG, ITEM_SILK_SCARF, ITEM_FAIRY_FEATHER, 0xFFFF}, //entry 0 - Ecruteak
	{ITEM_HEAT_ROCK, ITEM_DAMP_ROCK, ITEM_ICY_ROCK, ITEM_LIGHT_CLAY, ITEM_TERRAIN_EXTENDER, ITEM_RAZOR_CLAW, ITEM_RAZOR_FANG, ITEM_KINGS_ROCK, ITEM_PUNCHING_GLOVE, ITEM_EXPERT_BELT, ITEM_RED_CARD, ITEM_EJECT_BUTTON, 0xFFFF}, //entry 1 - Olivine
	{ITEM_KINGS_ROCK, ITEM_DEEP_SEA_TOOTH, ITEM_DEEP_SEA_SCALE, ITEM_METAL_COAT, ITEM_DRAGON_SCALE, ITEM_HARD_STONE, ITEM_BLACK_BELT, ITEM_MAGNET, ITEM_SPELL_TAG, ITEM_TWISTED_SPOON, ITEM_UP_GRADE, ITEM_PROTECTOR, ITEM_ELECTIRIZER, ITEM_MAGMARIZER, ITEM_DUBIOUS_DISC, ITEM_REAPER_CLOTH, ITEM_RAZOR_CLAW, ITEM_RAZOR_FANG, ITEM_PRISM_SCALE, ITEM_BLACK_AUGURITE, 0xFFFF}, //entry 1 - Safari Gate Evo Items
	{ITEM_TOXIC_ORB, ITEM_FLAME_ORB, ITEM_IRON_BALL, ITEM_LAGGING_TAIL, ITEM_BLACK_SLUDGE, ITEM_RING_TARGET, ITEM_DESTINY_KNOT, ITEM_STICKY_BARB, ITEM_SHED_SHELL, ITEM_ABSORB_BULB, ITEM_CELL_BATTERY, ITEM_EJECT_BUTTON, ITEM_RED_CARD, ITEM_LUMINOUS_MOSS, ITEM_SNOWBALL, ITEM_ADRENALINE_ORB, ITEM_BLUNDER_POLICY, ITEM_EJECT_PACK, ITEM_ROOM_SERVICE, 0xFFFF}, //entry 2 - Mahogany FIghtin' Grandma
	{ITEM_EXPERT_BELT, ITEM_LIFE_ORB, ITEM_ROCKY_HELMET, ITEM_ASSAULT_VEST, ITEM_PROTECTIVE_PADS, ITEM_HEAVY_DUTY_BOOTS, ITEM_CLEAR_AMULET, ITEM_COVERT_CLOAK, ITEM_WEAKNESS_POLICY, 0xFFFF}, //entry 3 - Blackthorn Ace Shop
};

u16 ALIGN4 OlivineMarts[][24] = 
{
	{ITEM_QUICK_CLAW, ITEM_WIDE_LENS, ITEM_AIR_BALLOON, ITEM_EVIOLITE, ITEM_FLOAT_STONE, ITEM_ZOOM_LENS, ITEM_METRONOME, ITEM_GRIP_CLAW, ITEM_BIG_ROOT, ITEM_BINDING_BAND, ITEM_LOADED_DICE, ITEM_PUNCHING_GLOVE, ITEM_THROAT_SPRAY, ITEM_ABILITY_SHIELD, 0xFFFF}, //entry 1 - Olivine
	{ITEM_LIGHT_CLAY, ITEM_ICY_ROCK, ITEM_SMOOTH_ROCK, ITEM_HEAT_ROCK, ITEM_DAMP_ROCK, ITEM_ELECTRIC_SEED, ITEM_GRASSY_SEED, ITEM_MISTY_SEED, ITEM_PSYCHIC_SEED, ITEM_TERRAIN_EXTENDER, ITEM_SAFETY_GOGGLES, ITEM_UTILITY_UMBRELLA, 0xFFFF}, //entry 1 - Olivine Beach Weather Items
};

u16 ALIGN4 BerryMarts[][24] = 
{
	{ITEM_CHERI_BERRY, ITEM_CHESTO_BERRY, ITEM_PECHA_BERRY, ITEM_RAWST_BERRY, ITEM_ASPEAR_BERRY, ITEM_PERSIM_BERRY, ITEM_LUM_BERRY, ITEM_LEPPA_BERRY, ITEM_ORAN_BERRY, ITEM_SITRUS_BERRY, ITEM_FIGY_BERRY, ITEM_WIKI_BERRY, ITEM_MAGO_BERRY, ITEM_AGUAV_BERRY, ITEM_IAPAPA_BERRY, ITEM_RAZZ_BERRY, ITEM_NANAB_BERRY, ITEM_PINAP_BERRY, 0xFFFF}, //entry 0 - Heal & Status Berries
	{ITEM_OCCA_BERRY, ITEM_PASSHO_BERRY, ITEM_WACAN_BERRY, ITEM_RINDO_BERRY, ITEM_YACHE_BERRY, ITEM_CHOPLE_BERRY, ITEM_KEBIA_BERRY, ITEM_SHUCA_BERRY, ITEM_COBA_BERRY, ITEM_PAYAPA_BERRY, ITEM_TANGA_BERRY, ITEM_CHARTI_BERRY, ITEM_KASIB_BERRY, ITEM_HABAN_BERRY, ITEM_COLBUR_BERRY, ITEM_BABIRI_BERRY, ITEM_ROSELI_BERRY, ITEM_CHILAN_BERRY, ITEM_ENIGMA_BERRY, 0xFFFF}, //entry 1 - Resist berries
	{ITEM_LIECHI_BERRY, ITEM_GANLON_BERRY, ITEM_SALAC_BERRY, ITEM_PETAYA_BERRY, ITEM_APICOT_BERRY, ITEM_LANSAT_BERRY, ITEM_STARF_BERRY, ITEM_MICLE_BERRY, ITEM_CUSTAP_BERRY, ITEM_JABOCA_BERRY, ITEM_ROWAP_BERRY, 0xFFFF}, //entry 2 - Pinch Berries
	{ITEM_POMEG_BERRY, ITEM_KELPSY_BERRY, ITEM_QUALOT_BERRY, ITEM_HONDEW_BERRY, ITEM_GREPA_BERRY, ITEM_TAMATO_BERRY, ITEM_DURIN_BERRY, 0xFFFF}, //entry 3 - EV Berries
};

u16 ALIGN4 TMMarts[][16] = 
{
	{ITEM_TM05, ITEM_TM17, ITEM_TM54, ITEM_TM58, 0xFFFF}, //entry 0 - Trainer Mart
	{ITEM_TM04, ITEM_TM08, ITEM_TM11, ITEM_TM18, ITEM_TM37, ITEM_TM69, ITEM_TM75, ITEM_TM77, 0xFFFF}, //entry 1 - Dance Mart
	{ITEM_TM14, ITEM_TM15, ITEM_TM22, ITEM_TM25, ITEM_TM26, ITEM_TM38, ITEM_TM52, ITEM_TM64, ITEM_TM68, ITEM_TM71, 0xFFFF}, //entry 2 - Power Mart
	{ITEM_TM13, ITEM_TM24, ITEM_TM29, ITEM_TM31, ITEM_TM32, ITEM_TM35, ITEM_TM81, 0xFFFF}, //entry 3 - Precision Mart
	{ITEM_TM06, ITEM_TM16, ITEM_TM20, ITEM_TM33, ITEM_TM42, ITEM_TM61, ITEM_TM73, ITEM_TM74, ITEM_TM76, ITEM_TM89, ITEM_TM90, 0xFFFF}, //entry 4 - Position Mart
};

u16 ALIGN4 TMMartAll[][96] = 
{
	{ITEM_TM01, ITEM_TM02, ITEM_TM03, ITEM_TM04, ITEM_TM05, ITEM_TM06, ITEM_TM07, ITEM_TM08, ITEM_TM09, ITEM_TM10, ITEM_TM11, ITEM_TM12, ITEM_TM13, ITEM_TM14, ITEM_TM15, ITEM_TM16, ITEM_TM17, ITEM_TM18, ITEM_TM19, ITEM_TM20, ITEM_TM21, ITEM_TM22, ITEM_TM23, ITEM_TM24, ITEM_TM25, ITEM_TM26, ITEM_TM27, ITEM_TM28, ITEM_TM29, ITEM_TM30, ITEM_TM31, ITEM_TM32, ITEM_TM33, ITEM_TM34, ITEM_TM35, ITEM_TM36, ITEM_TM37, ITEM_TM38, ITEM_TM39, ITEM_TM40, ITEM_TM41, ITEM_TM42, ITEM_TM43, ITEM_TM44, ITEM_TM45, ITEM_TM46, ITEM_TM47, ITEM_TM48, ITEM_TM49, ITEM_TM50, ITEM_TM51, ITEM_TM52, ITEM_TM53, ITEM_TM54, ITEM_TM55, ITEM_TM56, ITEM_TM57, ITEM_TM58, ITEM_TM59, ITEM_TM60, ITEM_TM61, ITEM_TM62, ITEM_TM63, ITEM_TM64, ITEM_TM65, ITEM_TM66, ITEM_TM67, ITEM_TM68, ITEM_TM69, ITEM_TM70, ITEM_TM71, ITEM_TM72, ITEM_TM73, ITEM_TM74, ITEM_TM75, ITEM_TM76, ITEM_TM77, ITEM_TM78, ITEM_TM79, ITEM_TM80, ITEM_TM81, ITEM_TM82, ITEM_TM83, ITEM_TM84, ITEM_TM85, ITEM_TM86, ITEM_TM87, ITEM_TM88, ITEM_TM89, ITEM_TM90, ITEM_TM91, ITEM_TM92, 0xFFFF}, //entry 0 - ALL TMs
};

u16 ALIGN4 MegaMart[][48] = 
{
	{ITEM_VENUSAURITE, ITEM_CHARIZARDITE_X, ITEM_CHARIZARDITE_Y, ITEM_BLASTOISINITE, ITEM_BEEDRILLITE, ITEM_PIDGEOTITE, ITEM_ALAKAZITE, ITEM_SLOWBRONITE, ITEM_GENGARITE, ITEM_KANGASKHANITE, ITEM_PINSIRITE, ITEM_GYARADOSITE, ITEM_AERODACTYLITE, ITEM_MEWTWONITE_X, ITEM_MEWTWONITE_Y, ITEM_AMPHAROSITE, ITEM_STEELIXITE, ITEM_SCIZORITE, ITEM_HERACRONITE, ITEM_HOUNDOOMINITE, ITEM_TYRANITARITE, ITEM_SCEPTILITE, ITEM_BLAZIKENITE, ITEM_SWAMPERTITE, ITEM_GARDEVOIRITE, ITEM_SABLENITE, ITEM_MAWILITE, ITEM_AGGRONITE, ITEM_MEDICHAMITE, ITEM_MANECTITE, ITEM_SHARPEDONITE, ITEM_CAMERUPTITE, ITEM_ALTARIANITE, ITEM_BANETTITE, ITEM_ABSOLITE, ITEM_GLALITITE, ITEM_SALAMENCITE, ITEM_METAGROSSITE, ITEM_LATIASITE, ITEM_LATIOSITE, ITEM_LOPUNNITE, ITEM_GARCHOMPITE, ITEM_LUCARIONITE, ITEM_ABOMASITE, ITEM_GALLADITE, ITEM_AUDINITE, ITEM_DIANCITE, 0xFFFF},
};


BOOL Script_RunNewCmd(SCRIPTCONTEXT *ctx) {
    u8 sw = ScriptReadByte(ctx);
    u16 UNUSED arg0 = ScriptReadHalfword(ctx);

    switch (sw) {
        case SCRIPT_NEW_CMD_REPEL_USE:;
#ifdef IMPLEMENT_REUSABLE_REPELS
            u16 most_recent_repel = Repel_GetMostRecent();
            SetScriptVar(arg0, most_recent_repel);
            Repel_Use(most_recent_repel, HEAPID_MAIN_HEAP);
#endif
            break;
		case SCRIPT_NEW_MARTS:;
			*(u32 *)(0x0210FA3C) = (u32)NewMarts[arg0];
			break;
		case SCRIPT_BERRY_MARTS:;
			*(u32 *)(0x0210FA3C) = (u32)BerryMarts[arg0];
			break;
		case SCRIPT_TM_MARTS:;
			*(u32 *)(0x0210FA3C) = (u32)TMMarts[arg0];
			break;
		case SCRIPT_TM_MART_ALL:;
			*(u32 *)(0x0210FA3C) = (u32)TMMartAll[arg0];
			break;
		case SCRIPT_OLIVINE_MARTS:;
			*(u32 *)(0x0210FA3C) = (u32)OlivineMarts[arg0];
			break;
		case SCRIPT_MEGA_MART:;
			*(u32 *)(0x0210FA3C) = (u32)MegaMart[arg0];
			break;			
		case SCRIPT_RESET_MART:;
			*(u32 *)(0x0210FA3C) = 0x020FBA54;
			break;
        default: break;
    }

    return FALSE;
}

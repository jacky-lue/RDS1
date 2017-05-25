//here is Global variable area.

#include "CauseEquip.h"

//For total error cause (Reading)
struct Encode_Cause_Equpiment_type RPT_all_Cause[CUASE_RPT_TABLE_SIZE]={
    0, "reserved",
    1, "Water temp sensor defect",
    2, "Hi-limit temp sensor defect",
    3, "Circ Pump defect",
    4, "Fuse on board defect",
    5, "Pipe Blockage",
    6, "Dirty Filter",
    7, "Flow Switch defect",
    8, "UV light expired",
    9, "Filter Cartridge expired",
    10, "Board defect",
    11, "Topside defect",
    12, "Pump-1 Hi (wire) defect",
    13, "Pump-1 Lo (wire) defect",
    14, "Pump-2 Hi (wire) defect",
    15, "Pump-2 Lo (wire) defect",
    16, "Pump-3 Hi (wire) defect",
    17, "Pump-3 Lo (wire) defect",
    18, "Blower (wire) defect",
    19, "Circ Pump + UV (wire) defect",
    20, "Heater (wire) defect"
};

struct Encode_Cause_Equpiment_type RPT_all_Equip[EQUIP_RPT_TABLE_SIZE]={
    0, "Reserved",
    1, "Water temp sensor (001-2100)",
    2, "Hi-limit temp sensor (002-2231)",
    3, "Circ. Pump (003-3198)",
    4, "Fuse (004-1295)",
    5, "Pipe (005-4311)",
    6, "Filter cartridge (006-2349)",
    7, "Flow Switch (007-2918)",
    8, "UV light (008-2366)",
    9, "Filter Cartridge (006-2349)",
    10, "Board (010-5512)",
    11, "Topside (011-2198)",
    12, "Pump-1 (012-2508)",
    13, "Pump-1 (012-2508)",
    14, "Pump-2 (014-0098)",
    15, "Pump-2 (014-0098)",
    16, "Pump-3 (016-8087)",
    17, "Pump-3 (016-8087)",
    18, "Blower (018-7721)",
    19, "Circ. Pump + UV light",
    20, "Heater (020-6515)"
};
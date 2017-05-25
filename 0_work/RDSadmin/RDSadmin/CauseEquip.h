#define CUASE_RPT_TABLE_SIZE		26
#define EQUIP_RPT_TABLE_SIZE		26

struct Encode_Cause_Equpiment_type
{
    unsigned char code;    //0=none, encoding from 1,2,3...
    char* CE_string;
};

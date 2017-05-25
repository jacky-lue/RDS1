#include "SPA.h"

#include <cmath>

using namespace SPAnamespace;

#define LENGTH_OF_VOLT_ADC_TABLE	37
const unsigned int Voltage_ADC_Table[LENGTH_OF_VOLT_ADC_TABLE]=
{
    136, // 80V
    147, // 85V
    158, // 90V
    169, // 95V
    180, //100V
    191, //105V
    202, //110V
    213, //115V
    224, //120V
    236, //125V
    248, //130V
    260, //135V
    272, //140V
    283, //145V
    294, //150V
    305, //155V
    316, //160V
    327, //165V
    338, //170V
    349, //175V
    361, //180V
    373, //185V
    384, //190V
    395, //195V
    406, //200V
    417, //205V
    428, //210V
    439, //215V
    450, //220V
    462, //225V
    473, //230V
    484, //235V
    495, //240V
    506, //245V
    517, //250V
    528, //255V
    539  //260V
};

const  unsigned int TEMP_F_To_TEMPADC_Table[42]=
//unsigned int TEMP_F_To_TEMPADC_Table[27]=
{
    682,   //65
    677,   //66
    671,   //67
    664,   //68
    659,   //69
    653,   //70
    648,   //71
    642,   //72
    636,   //73
    630,   //74
    625,   //75
    618,   //76
    612,   //77
    607,   //78
    601,   //79
    595,   //80
    589,   //81
    583,   //82
    577,   //83
    571,   //84
    565,   //85
    559,   //86
    553,   //87
    547,   //88
    541,   //89
    536,   //90
    530,   //91
    524,   //92
    518,   //93
    513,   //94
    507,   //95
    501,   //96
    494,   //97
    489,   //98
    484,   //99
    478,   //100
    473,   //101
    467,   //102
    461,   //103
    455,   //104
    449,   //105
    444,   //106
};

const  unsigned int TEMP_C_To_TEMPADC_Table[45]=
//unsigned int TEMP_C_To_TEMPADC_Table[29]=
{
    687,   //18.0
    682,   //18.5
    677,   //19.0
    672,   //19.5
    667,   //20.0
    661,   //20.5
    656,   //21.0
    651,   //21.5
    646,   //22.0
    641,   //22.5
    635,   //23.0
    630,   //23.5
    625,   //24.0
    620,   //24.5
    614,   //25.0
    609,   //25.5
    604,   //26.0
    599,   //26.5
    593,   //27.0
    588,   //27.5
    583,   //28.0
    577,   //28.5
    572,   //29.0
    567,   //29.5
    561,   //30.0
    556,   //30.5
    551,   //31.0
    546,   //31.5
    540,   //32.0
    535,   //32.5
    530,   //33.0
    524,   //33.5
    519,   //34.0
    514,   //34.5
    509,   //35.0
    504,   //35.5
    498,   //36.0
    493,   //36.5
    488,   //37.0
    483,   //37.5
    478,   //38.0
    473,   //38.5
    468,   //39.0
    463,   //39.5
    457    //40.0
};

const unsigned int Ctemptab[]={
    717, 716, 715, 714, 713, 712, 711, 710, 709, 708,  //15.0-15.9
    707, 706, 705, 704, 703, 702, 701, 700, 699, 698,  //16.0-16.9
    697, 696, 695, 694, 693, 692, 691, 690, 689, 688,  //17.0-17.9
    687, 686, 685, 684, 683, 682, 681, 680, 679, 678,  //18
    677, 676, 675, 674, 673, 672, 671, 670, 669, 668,  //19
    667, 666, 665, 664, 663, 661, 660, 659, 658, 657,  //20
    656, 655, 654, 653, 652, 651, 650, 649, 648, 647,  //21
    646, 645, 644, 643, 642, 641, 640, 639, 638, 636,  //22
    635, 634, 633, 632, 631, 630, 629, 628, 627, 626,  //23
    625, 624, 623, 622, 621, 620, 619, 618, 617, 615,  //24
    614, 613, 612, 611, 610, 609, 608, 607, 606, 605,  //25
    604, 603, 602, 601, 600, 599, 598, 596, 595, 594,  //26
    593, 592, 591, 590, 589, 588, 587, 586, 585, 584,  //27
    583, 582, 581, 579, 578, 577, 576, 575, 574, 573,  //28
    572, 571, 570, 569, 568, 567, 566, 565, 564, 562,  //29
    561, 560, 559, 558, 557, 556, 555, 554, 553, 552,  //30
    551, 550, 549, 548, 547, 546, 544, 543, 542, 541,  //31
    540, 539, 538, 537, 536, 535, 534, 533, 532, 531,  //32
    530, 529, 528, 527, 526, 524, 523, 522, 521, 520,  //33
    519, 518, 517, 516, 515, 514, 513, 512, 511, 510,  //34
    509, 508, 507, 506, 505, 504, 503, 501, 500, 499,  //35
    498, 497, 496, 495, 494, 493, 492, 491, 490, 489,  //36
    488, 487, 486, 485, 484, 483, 482, 481, 480, 479,  //37
    478, 477, 476, 475, 474, 473, 472, 471, 470, 469,  //38
    468, 467, 466, 465, 464, 463, 462, 460, 459, 458,  //39
    457, 456, 455, 454, 453, 452, 451, 450, 449, 448,  //40
    447, 446, 445, 444, 443, 442, 441, 440, 439, 438,  //41
    437, 436, 435, 434, 433, 432, 431, 430, 429, 428,  //42
    427, 426, 425, 424, 423, 422, 421, 420, 419, 418,  //43
    417, 416, 415, 414, 413, 412, 411, 410, 409, 408,  //44
    407, 406, 405, 404, 403, 402, 401, 400, 399, 398,  //45.0-45.9
};

const unsigned int ADC_To_C_Tab[]={
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159,  //15.0-15.9
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169,  //16.0-16.9
    170, 171, 172, 173, 174, 175, 176, 177, 178, 179,  //17.0-17.9
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189,  //18
    190, 191, 192, 193, 194, 195, 196, 197, 198, 199,  //19
    200, 201, 202, 203, 204, 205, 205, 206, 207, 208, 209,  //20
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219,  //21
    220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 229,  //22
    230, 231, 232, 233, 234, 235, 236, 237, 238, 239,  //23
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 249,  //24
    250, 251, 252, 253, 254, 255, 256, 257, 258, 259,  //25
    260, 261, 262, 263, 264, 265, 266, 267, 267, 268, 269,  //26
    270, 271, 272, 273, 274, 275, 276, 277, 278, 279,  //27
    280, 281, 282, 283, 283, 284, 285, 286, 287, 288, 289,  //28
    290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 299,  //29
    300, 301, 302, 303, 304, 305, 306, 307, 308, 309,  //30
    310, 311, 312, 313, 314, 315, 316, 316, 317, 318, 319,  //31
    320, 321, 322, 323, 324, 325, 326, 327, 328, 329,  //32
    330, 331, 332, 333, 334, 335, 335, 336, 337, 338, 339,  //33
    340, 341, 342, 343, 344, 345, 346, 347, 348, 349,  //34
    350, 351, 352, 353, 354, 355, 356, 357, 357, 358, 359,  //35
    360, 361, 362, 363, 364, 365, 366, 367, 368, 369,  //36
    370, 371, 372, 373, 374, 375, 376, 377, 378, 379,  //37
    380, 381, 382, 383, 384, 385, 386, 387, 388, 389,  //38
    390, 391, 392, 393, 394, 395, 396, 397, 397, 398, 399,  //39
    400, 401, 402, 403, 404, 405, 406, 407, 408, 409,  //40
    410, 411, 412, 413, 414, 415, 416, 417, 418, 419,  //41
    420, 421, 422, 423, 424, 425, 426, 427, 428, 429,  //42
    430, 431, 432, 433, 434, 435, 436, 437, 438, 439,  //43
    440, 441, 442, 443, 444, 445, 446, 447, 448, 449,  //44
    450, 451, 452, 453, 454, 455, 456, 457, 458, 459,  //45.0-45.9
};

#define   Ctemptab0    	150    	   	// table[0] temperature : 15.0
#define   CtemptblNo   	( sizeof (Ctemptab) / sizeof (Ctemptab[0] ) )

SPA::SPA()
{
    //Initial all UI variable-----------------
    p1_hi_on=false; p1_lo_on=false;
    p2_hi_on=false; p2_lo_on=false;
    p3_hi_on=false; p3_lo_on=false;

    blower_on=true;
    circ_on=true;
    uv_on=true;
    heater_on=true;
    ozon_on=false;

    //lock
    unlock=false;
    lock_Tmpr=false;
    lock_Func=false;
    lock_Pump=false;
    lock_Panl=false;

    //Eco/std mode
    ecoModeOn=false;

    //err message area
    msg_index_1=31; msg_index_2=31; msg_index_3=31; msg_index_4=31;
    msg_more_than_4=false;

    //relay err
    relay_err_p1=false;
    relay_err_p2=false;
    relay_err_p3=false;
    relay_err_ht=false;

    //days
    uv_days=300;
    filter_days=300;
}

unsigned int SPA::TEMP_F_To_TEMPADC(unsigned int Temperature)
{
    //return TEMP_F_To_TEMPADC_Table[Temperature - 80];
    return TEMP_F_To_TEMPADC_Table[Temperature-65];
}

unsigned int SPA::TEMP_C_To_TEMPADC(unsigned int Temperature)
{
    //return TEMP_C_To_TEMPADC_Table[Temperature - 260];
    unsigned char i;
    unsigned int j;
    Temperature=Temperature-180;
    i=Temperature/5;
    j=TEMP_C_To_TEMPADC_Table[i];
    return j;
}

//2 盢放ADC锣Θ地ん计
unsigned int SPA::TEMPADC_To_TEMP_F(unsigned int TemperatureADC)
{
    unsigned int temp;

    if((TemperatureADC>=539)&&(TemperatureADC<=1024))//<=89.9F
    {
        if(TemperatureADC>717)//<59.0F
        {
            temp=TemperatureADC-717;
            temp=temp/5;
            temp=59-temp;
            return temp;
        }
        else if(TemperatureADC>=656)//59.0 - 69.9
        {
            if(TemperatureADC>=712) return 59;
            else if(TemperatureADC>=707) return 60;
            else if(TemperatureADC>=701) return 61;
            else if(TemperatureADC>=696) return 62;
            else if(TemperatureADC>=690) return 63;
            else if(TemperatureADC>=685) return 64;
            else if(TemperatureADC>=679) return 65;
            else if(TemperatureADC>=674) return 66;
            else if(TemperatureADC>=668) return 67;
            else if(TemperatureADC>=661) return 68;
            else if(TemperatureADC>=656) return 69;
        }
        else if(TemperatureADC>=598) //70.0 -79.9
        {
            if(TemperatureADC>=650) return 70;
            else if(TemperatureADC>=645) return 71;
            else if(TemperatureADC>=639) return 72;
            else if(TemperatureADC>=633) return 73;
            else if(TemperatureADC>=627) return 74;
            else if(TemperatureADC>=622) return 75;
            else if(TemperatureADC>=615) return 76;
            else if(TemperatureADC>=609) return 77;
            else if(TemperatureADC>=604) return 78;
            else if(TemperatureADC>=598) return 79;
        }
        else if(TemperatureADC>=539)//80.0 - 89.9
        {
            if(TemperatureADC>=592) return 80;
            else if(TemperatureADC>=586) return 81;
            else if(TemperatureADC>=581) return 82;
            else if(TemperatureADC>=574) return 83;
            else if(TemperatureADC>=569) return 84;
            else if(TemperatureADC>=562) return 85;
            else if(TemperatureADC>=556) return 86;
            else if(TemperatureADC>=551) return 87;
            else if(TemperatureADC>=544) return 88;
            else if(TemperatureADC>=539) return 89;
        }
    }
    else if(TemperatureADC<539)//>89.9F
    {
        if(TemperatureADC>=481)//90.0 - 99.9
        {
            if(TemperatureADC>=533) return 90;
            else if(TemperatureADC>=528) return 91;
            else if(TemperatureADC>=521) return 92;
            else if(TemperatureADC>=516) return 93;
            else if(TemperatureADC>=510) return 94;
            else if(TemperatureADC>=504) return 95;
            else if(TemperatureADC>=498) return 96;
            else if(TemperatureADC>=492) return 97;
            else if(TemperatureADC>=487) return 98;
            else if(TemperatureADC>=481) return 99;
        }
        else if(TemperatureADC>=426)//100.0 - 109.9
        {
            if(TemperatureADC>=476) return 100;
            else if(TemperatureADC>=470) return 101;
            else if(TemperatureADC>=465) return 102;
            else if(TemperatureADC>=458) return 103;
            else if(TemperatureADC>=452) return 104;
            else if(TemperatureADC>=447) return 105;
            else if(TemperatureADC>=442) return 106;
            else if(TemperatureADC>=437) return 107;
            else if(TemperatureADC>=431) return 108;
            else if(TemperatureADC>=426) return 109;
        }
        else if(TemperatureADC>=398)//110.0 - 114.9
        {
            if(TemperatureADC>=420) return 110;
            else if(TemperatureADC>=415) return 111;
            else if(TemperatureADC>=410) return 112;
            else if(TemperatureADC>=404) return 113;
            else if(TemperatureADC>=398) return 114;
        }
        else // >114.9
        {
            temp=397-TemperatureADC;
            temp=temp/5;
            temp=115+temp;

            if(temp>255)
                return 255;
            else
                return temp;
        }
    }

    return 0;
}

//2 盢放ADC锣Θ尼ん计
unsigned int SPA::TEMPADC_To_TEMP_C(unsigned int TemperatureADC)
{
    unsigned int i;
    int rc;
    //if ( TemperatureADC >= Ctemptab[0] )	//left side 15C
    if(TemperatureADC>=717)	//left side 15C
    {
        //rc = Ctemptab0 - (TemperatureADC + 20 - Ctemptab[0]);
        rc=Ctemptab0-(TemperatureADC-697);
    }
    //else if(TemperatureADC<=Ctemptab[CtemptblNo-1])	//right side  46C
    else if(TemperatureADC<=398)	//right side  46C
    {
        //rc =  Ctemptab0 + CtemptblNo + (Ctemptab[CtemptblNo-1]-TemperatureADC);
        rc=Ctemptab0+300+(398-TemperatureADC);
    }
    else  //in between 15~46C
    {
        rc=ADC_To_C_Tab[717-TemperatureADC];
    }
    return rc;
}

//---

unsigned int SPA::VoltageADC_to_Volt(unsigned int VoltageADC)
{
    int i, foundInTable;
    float ratio;
    unsigned int preV, nextV;
    unsigned int rtnV;
    unsigned int preVadc, nextVadc;
    foundInTable=-1;
    for(i=0; i<LENGTH_OF_VOLT_ADC_TABLE-1; i++)
    {
        preVadc=Voltage_ADC_Table[i];
        nextVadc=Voltage_ADC_Table[i+1];
        if(VoltageADC>=preVadc && VoltageADC<=nextVadc)
        {
            foundInTable=i;
        }
    }
    if(foundInTable==-1)
    {
        //out of table
        return -1;
    }
    else
    {
        preVadc=Voltage_ADC_Table[foundInTable];
        nextVadc=Voltage_ADC_Table[foundInTable+1];
        preV=80+(foundInTable*5);
        nextV=80+((foundInTable+1)*5);
        ratio=(float)(VoltageADC-preVadc)/(nextVadc-preVadc);
        rtnV=preV+5*ratio;
        return rtnV;
    }
}

unsigned int SPA::CurrentADC_to_Amp(unsigned int CurrentADC)
{
    unsigned int rtnC;
    //PS: return value should be
    rtnC=round(CurrentADC * (float)0.089); //0.0785 (2016/02/25 change to 0.089)
    return rtnC;
    //return rtn_Amp;
}

unsigned int SPA::CurrentADC_to_Amp_dot1(unsigned int CurrentADC)
{
    unsigned int rtnC;
    //PS: return value should be
    rtnC=round(CurrentADC*10*(float)0.089); //0.0785 (2016/02/25 change to 0.089)
    return rtnC;
    //return rtn_Amp;
}
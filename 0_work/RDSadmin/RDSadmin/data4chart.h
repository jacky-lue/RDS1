// for program control
#define DASHBOARD2_CHART1_SERIES_LENNGTH	10
#define DASHBOARD2_CHART1_TOTAL_OSC			332
#define DASHBOARD2_CHART2_SERIES_LENNGTH	10
#define DASHBOARD2_CHART3_SERIES_LENNGTH	4
#define DASHBOARD2_CHART4_SERIES_LENNGTH	9
#define DASHBOARD2_CHART5_SERIES_LENNGTH	10
#define DASHBOARD2_CHART6_SERIES_LENNGTH	6

//-------- Dsplay String ---------------
#define CHART_1_TITLE_FIRST		"Total Open Service Calls:"
#define CHART_1_TITLE_SECOND	"Rank by Dealer"
//
#define CHART_2_TITLE_FIRST		"Dealer Efficiency by Rank"
#define CHART_2_SERIES_TOOLTIP  "Average Ticket Closed Days"
//
#define CHART_3_TITLE_FIRST		"Services Calls by Channel"
#define CHART_3_SERIES_TOOLTIP  "calls from: "
//
#define CHART_4_TITLE_FIRST		"Repaired Parts Rank"
//
#define CHART_5_TITLE_FIRST		"Error Code Rank by Frequency"
//
#define CHART_6_TITLE_FIRST		"Services Calls by Hot Tube Model"
#define CHART_6_SERIES_TOOLTIP  "calls for model: "

//========================================
struct ChartArea_1_XY_type
{
    char* dealer_name;
    unsigned int calls;
};

struct ChartArea_2_XY_type
{
    char* dealer_name;
    float effct;
};

struct ChartArea_3_XY_type
{
    char* channel_name;
    int calls;
};

struct ChartArea_4_XY_type
{
    char* part_name;
    unsigned int number;
};

struct ChartArea_5_XY_type
{
    char* Error_name;
    unsigned int times;
};

struct ChartArea_6_XY_type
{
    char* model_name;
    int calls;
};
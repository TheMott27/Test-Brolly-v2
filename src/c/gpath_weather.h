#pragma once
#include <pebble.h>

// ─────────────────────────────────────────────────────────────────────────────
// Weather icon GPath data for Brolly v2.0.0
// All coordinates are post-crop (origin at top-left of drawn area).
// Native dimensions (w×h) are given per icon for scaling.
// ─────────────────────────────────────────────────────────────────────────────

// ── Icon IDs ─────────────────────────────────────────────────────────────────
typedef enum {
  GPATH_ID_CLOUDY_DAY = 0,
  GPATH_ID_THUNDERSTORM,
  GPATH_ID_HEAVY_RAIN,
  GPATH_ID_HEAVY_SNOW,
  GPATH_ID_LIGHT_RAIN,
  GPATH_ID_LIGHT_SNOW,
  GPATH_ID_RAINING_AND_SNOWING,
  GPATH_ID_PARTLY_CLOUDY,
  GPATH_ID_TIMELINE_SUN,
  GPATH_ID_TIMELINE_MOON,
  GPATH_ID_PARTLY_CLOUDY_NIGHT,
  GPATH_ID_UNKNOWN,
  GPATH_ID_COUNT
} GPathIconID;

// ── Struct to hold a multi-path icon ─────────────────────────────────────────
typedef struct {
  int native_w;
  int native_h;
  int num_paths;
  const GPathInfo *paths;
} WeatherIconDef;

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_CLOUDY_DAY — native 23×14
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_cloudy_day_0_pts[] = {
  {21,14},{23,12},{23,8},{20,4},{16,4},{13,0},{8,0},{4,4},{2,4},{0,6},{0,12},{2,14},{21,14}
};
static const GPoint s_cloudy_day_1_pts[] = {
  {4,4},{7,7}
};
static const GPathInfo s_cloudy_day_paths[] = {
  { ARRAY_LENGTH(s_cloudy_day_0_pts), (GPoint *)s_cloudy_day_0_pts },
  { ARRAY_LENGTH(s_cloudy_day_1_pts), (GPoint *)s_cloudy_day_1_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_THUNDERSTORM — native 23×18
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_thunderstorm_0_pts[] = {
  {8,0},{4,4},{2,4},{0,6},{0,12},{2,14},{7,14}
};
static const GPoint s_thunderstorm_1_pts[] = {
  {18,14},{21,14},{23,12},{23,8},{20,4},{17,4}
};
static const GPoint s_thunderstorm_2_pts[] = {
  {17,4},{13,0},{8,0}
};
static const GPoint s_thunderstorm_3_pts[] = {
  {12,2},{6,10},{10,10},{7,18},{18,8},{13,8},{12,2}
};
static const GPathInfo s_thunderstorm_paths[] = {
  { ARRAY_LENGTH(s_thunderstorm_0_pts), (GPoint *)s_thunderstorm_0_pts },
  { ARRAY_LENGTH(s_thunderstorm_1_pts), (GPoint *)s_thunderstorm_1_pts },
  { ARRAY_LENGTH(s_thunderstorm_2_pts), (GPoint *)s_thunderstorm_2_pts },
  { ARRAY_LENGTH(s_thunderstorm_3_pts), (GPoint *)s_thunderstorm_3_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_HEAVY_RAIN — native 23×22
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_heavy_rain_0_pts[] = {
  {21,11},{23,9},{23,6},{20,3},{16,3},{13,0},{8,0},{5,3},{3,3},{0,6},{0,9},{2,11},{21,11}
};
static const GPoint s_heavy_rain_1_pts[] = { {1,22},{3,14} };
static const GPoint s_heavy_rain_2_pts[] = { {6,22},{8,14} };
static const GPoint s_heavy_rain_3_pts[] = { {12,18},{13,14} };
static const GPoint s_heavy_rain_4_pts[] = { {17,18},{18,14} };
static const GPathInfo s_heavy_rain_paths[] = {
  { ARRAY_LENGTH(s_heavy_rain_0_pts), (GPoint *)s_heavy_rain_0_pts },
  { ARRAY_LENGTH(s_heavy_rain_1_pts), (GPoint *)s_heavy_rain_1_pts },
  { ARRAY_LENGTH(s_heavy_rain_2_pts), (GPoint *)s_heavy_rain_2_pts },
  { ARRAY_LENGTH(s_heavy_rain_3_pts), (GPoint *)s_heavy_rain_3_pts },
  { ARRAY_LENGTH(s_heavy_rain_4_pts), (GPoint *)s_heavy_rain_4_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_HEAVY_SNOW — native 23×23
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_heavy_snow_0_pts[] = {
  {21,11},{23,9},{23,5},{21,3},{16,3},{13,0},{7,0},{4,3},{2,3},{0,5},{0,9},{2,11},{21,11}
};
static const GPoint s_heavy_snow_1_pts[] = { {4,3},{7,6} };
static const GPoint s_heavy_snow_2_pts[] = { {4,18},{4,14} };
static const GPoint s_heavy_snow_3_pts[] = { {2,16},{6,16} };
static const GPoint s_heavy_snow_4_pts[] = { {10,23},{10,19} };
static const GPoint s_heavy_snow_5_pts[] = { {8,21},{12,21} };
static const GPoint s_heavy_snow_6_pts[] = { {15,18},{15,14} };
static const GPoint s_heavy_snow_7_pts[] = { {13,16},{17,16} };
static const GPathInfo s_heavy_snow_paths[] = {
  { ARRAY_LENGTH(s_heavy_snow_0_pts), (GPoint *)s_heavy_snow_0_pts },
  { ARRAY_LENGTH(s_heavy_snow_1_pts), (GPoint *)s_heavy_snow_1_pts },
  { ARRAY_LENGTH(s_heavy_snow_2_pts), (GPoint *)s_heavy_snow_2_pts },
  { ARRAY_LENGTH(s_heavy_snow_3_pts), (GPoint *)s_heavy_snow_3_pts },
  { ARRAY_LENGTH(s_heavy_snow_4_pts), (GPoint *)s_heavy_snow_4_pts },
  { ARRAY_LENGTH(s_heavy_snow_5_pts), (GPoint *)s_heavy_snow_5_pts },
  { ARRAY_LENGTH(s_heavy_snow_6_pts), (GPoint *)s_heavy_snow_6_pts },
  { ARRAY_LENGTH(s_heavy_snow_7_pts), (GPoint *)s_heavy_snow_7_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_LIGHT_RAIN — native 23×23
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_light_rain_0_pts[] = {
  {21,11},{23,9},{23,5},{21,3},{16,3},{13,0},{7,0},{4,3},{2,3},{0,5},{0,9},{2,11},{21,11}
};
static const GPoint s_light_rain_1_pts[] = { {4,3},{7,6} };
static const GPoint s_light_rain_2_pts[] = { {13,17},{13,14} };
static const GPoint s_light_rain_3_pts[] = { {3,17},{3,14} };
static const GPoint s_light_rain_4_pts[] = { {8,20},{8,17} };
static const GPoint s_light_rain_5_pts[] = { {3,23},{3,20} };
static const GPathInfo s_light_rain_paths[] = {
  { ARRAY_LENGTH(s_light_rain_0_pts), (GPoint *)s_light_rain_0_pts },
  { ARRAY_LENGTH(s_light_rain_1_pts), (GPoint *)s_light_rain_1_pts },
  { ARRAY_LENGTH(s_light_rain_2_pts), (GPoint *)s_light_rain_2_pts },
  { ARRAY_LENGTH(s_light_rain_3_pts), (GPoint *)s_light_rain_3_pts },
  { ARRAY_LENGTH(s_light_rain_4_pts), (GPoint *)s_light_rain_4_pts },
  { ARRAY_LENGTH(s_light_rain_5_pts), (GPoint *)s_light_rain_5_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_LIGHT_SNOW — native 23×23
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_light_snow_0_pts[] = {
  {21,11},{23,9},{23,5},{21,3},{16,3},{13,0},{7,0},{4,3},{2,3},{0,5},{0,9},{2,11},{21,11}
};
static const GPoint s_light_snow_1_pts[] = { {4,3},{7,6} };
static const GPoint s_light_snow_2_pts[] = { {4,18},{4,14} };
static const GPoint s_light_snow_3_pts[] = { {2,16},{6,16} };
static const GPoint s_light_snow_4_pts[] = { {10,23},{10,19} };
static const GPoint s_light_snow_5_pts[] = { {8,21},{12,21} };
static const GPathInfo s_light_snow_paths[] = {
  { ARRAY_LENGTH(s_light_snow_0_pts), (GPoint *)s_light_snow_0_pts },
  { ARRAY_LENGTH(s_light_snow_1_pts), (GPoint *)s_light_snow_1_pts },
  { ARRAY_LENGTH(s_light_snow_2_pts), (GPoint *)s_light_snow_2_pts },
  { ARRAY_LENGTH(s_light_snow_3_pts), (GPoint *)s_light_snow_3_pts },
  { ARRAY_LENGTH(s_light_snow_4_pts), (GPoint *)s_light_snow_4_pts },
  { ARRAY_LENGTH(s_light_snow_5_pts), (GPoint *)s_light_snow_5_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_RAINING_AND_SNOWING — native 23×23
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_rain_snow_0_pts[] = {
  {21,11},{23,9},{23,5},{21,3},{16,3},{13,0},{7,0},{4,3},{2,3},{0,5},{0,9},{2,11},{21,11}
};
static const GPoint s_rain_snow_1_pts[] = { {4,3},{7,6} };
static const GPoint s_rain_snow_2_pts[] = { {4,18},{4,14} };
static const GPoint s_rain_snow_3_pts[] = { {10,23},{10,19} };
static const GPoint s_rain_snow_4_pts[] = { {15,18},{15,14} };
static const GPoint s_rain_snow_5_pts[] = { {13,16},{17,16} };
static const GPathInfo s_rain_snow_paths[] = {
  { ARRAY_LENGTH(s_rain_snow_0_pts), (GPoint *)s_rain_snow_0_pts },
  { ARRAY_LENGTH(s_rain_snow_1_pts), (GPoint *)s_rain_snow_1_pts },
  { ARRAY_LENGTH(s_rain_snow_2_pts), (GPoint *)s_rain_snow_2_pts },
  { ARRAY_LENGTH(s_rain_snow_3_pts), (GPoint *)s_rain_snow_3_pts },
  { ARRAY_LENGTH(s_rain_snow_4_pts), (GPoint *)s_rain_snow_4_pts },
  { ARRAY_LENGTH(s_rain_snow_5_pts), (GPoint *)s_rain_snow_5_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_PARTLY_CLOUDY — native 23×24
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_partly_cloudy_0_pts[] = {
  {12,4},{10,6},{10,9},{12,11},{15,11},{17,9},{17,6},{15,4},{12,4}
};
static const GPoint s_partly_cloudy_1_pts[] = { {6,1},{8,3} };
static const GPoint s_partly_cloudy_2_pts[] = { {21,1},{19,3} };
static const GPoint s_partly_cloudy_3_pts[] = {
  {21,24},{23,22},{23,18},{21,16},{15,16},{12,13},{8,13},{5,16},{2,16},{0,18},{0,22},{2,24},{21,24}
};
static const GPoint s_partly_cloudy_4_pts[] = { {5,16},{8,19} };
static const GPoint s_partly_cloudy_5_pts[] = { {20,8},{23,8} };
static const GPoint s_partly_cloudy_6_pts[] = { {4,8},{7,8} };
static const GPoint s_partly_cloudy_7_pts[] = { {13,0},{13,3} };
static const GPathInfo s_partly_cloudy_paths[] = {
  { ARRAY_LENGTH(s_partly_cloudy_0_pts), (GPoint *)s_partly_cloudy_0_pts },
  { ARRAY_LENGTH(s_partly_cloudy_1_pts), (GPoint *)s_partly_cloudy_1_pts },
  { ARRAY_LENGTH(s_partly_cloudy_2_pts), (GPoint *)s_partly_cloudy_2_pts },
  { ARRAY_LENGTH(s_partly_cloudy_3_pts), (GPoint *)s_partly_cloudy_3_pts },
  { ARRAY_LENGTH(s_partly_cloudy_4_pts), (GPoint *)s_partly_cloudy_4_pts },
  { ARRAY_LENGTH(s_partly_cloudy_5_pts), (GPoint *)s_partly_cloudy_5_pts },
  { ARRAY_LENGTH(s_partly_cloudy_6_pts), (GPoint *)s_partly_cloudy_6_pts },
  { ARRAY_LENGTH(s_partly_cloudy_7_pts), (GPoint *)s_partly_cloudy_7_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_TIMELINE_SUN — native 22×23
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_timeline_sun_0_pts[] = {
  {9,5},{5,9},{5,13},{9,17},{13,17},{17,13},{17,9},{13,5},{9,5}
};
static const GPoint s_timeline_sun_1_pts[] = { {11,0},{11,2} };
static const GPoint s_timeline_sun_2_pts[] = { {11,23},{11,20} };
static const GPoint s_timeline_sun_3_pts[] = { {0,22},{4,18} };
static const GPoint s_timeline_sun_4_pts[] = { {2,2},{4,4} };
static const GPoint s_timeline_sun_5_pts[] = { {22,22},{18,18} };
static const GPoint s_timeline_sun_6_pts[] = { {20,2},{18,4} };
static const GPoint s_timeline_sun_7_pts[] = { {2,11},{0,11} };
static const GPoint s_timeline_sun_8_pts[] = { {22,11},{20,11} };
static const GPathInfo s_timeline_sun_paths[] = {
  { ARRAY_LENGTH(s_timeline_sun_0_pts), (GPoint *)s_timeline_sun_0_pts },
  { ARRAY_LENGTH(s_timeline_sun_1_pts), (GPoint *)s_timeline_sun_1_pts },
  { ARRAY_LENGTH(s_timeline_sun_2_pts), (GPoint *)s_timeline_sun_2_pts },
  { ARRAY_LENGTH(s_timeline_sun_3_pts), (GPoint *)s_timeline_sun_3_pts },
  { ARRAY_LENGTH(s_timeline_sun_4_pts), (GPoint *)s_timeline_sun_4_pts },
  { ARRAY_LENGTH(s_timeline_sun_5_pts), (GPoint *)s_timeline_sun_5_pts },
  { ARRAY_LENGTH(s_timeline_sun_6_pts), (GPoint *)s_timeline_sun_6_pts },
  { ARRAY_LENGTH(s_timeline_sun_7_pts), (GPoint *)s_timeline_sun_7_pts },
  { ARRAY_LENGTH(s_timeline_sun_8_pts), (GPoint *)s_timeline_sun_8_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_TIMELINE_MOON — native 15×22
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_timeline_moon_0_pts[] = {
  {0,1},{3,0},{5,0},{7,0},{9,1},{10,2},{12,3},{13,5},{14,7},{15,9},{15,11},
  {15,13},{14,15},{13,17},{12,19},{10,20},{9,21},{7,22},{5,22},{3,22},{1,21},
  {2,21},{4,20},{5,18},{6,17},{7,15},{8,13},{8,11},{8,9},{7,7},{6,5},{5,4},
  {4,2},{2,1},{1,1},{0,1}
};
static const GPathInfo s_timeline_moon_paths[] = {
  { ARRAY_LENGTH(s_timeline_moon_0_pts), (GPoint *)s_timeline_moon_0_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_PARTLY_CLOUDY_NIGHT — native 23×23
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_partly_cloudy_night_0_pts[] = {
  {12,0},{13,0},{14,0},{15,0},{16,0},{17,1},{18,2},{19,3},{19,4},{19,5},{19,6},
  {19,7},{18,8},{17,9},{16,10},{15,10},{14,10},{13,10},{12,10},{13,10},{13,9},
  {14,9},{15,8},{15,7},{15,6},{15,5},{15,4},{15,3},{15,2},{14,1},{13,1},{13,0},{12,0}
};
static const GPoint s_partly_cloudy_night_1_pts[] = {
  {21,23},{23,21},{23,17},{21,15},{15,15},{12,12},{8,12},{5,15},{2,15},{0,17},{0,21},{2,23},{21,23}
};
static const GPoint s_partly_cloudy_night_2_pts[] = { {5,15},{8,18} };
static const GPathInfo s_partly_cloudy_night_paths[] = {
  { ARRAY_LENGTH(s_partly_cloudy_night_0_pts), (GPoint *)s_partly_cloudy_night_0_pts },
  { ARRAY_LENGTH(s_partly_cloudy_night_1_pts), (GPoint *)s_partly_cloudy_night_1_pts },
  { ARRAY_LENGTH(s_partly_cloudy_night_2_pts), (GPoint *)s_partly_cloudy_night_2_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// GPATH_UNKNOWN — native 22×22
// ─────────────────────────────────────────────────────────────────────────────
static const GPoint s_unknown_0_pts[] = {
  {11,0},{22,11},{11,22},{0,11},{11,0}
};
static const GPoint s_unknown_1_pts[] = {
  {8,7},{9,5},{11,4},{13,5},{13,8},{11,10},{11,13}
};
static const GPoint s_unknown_2_pts[] = { {11,16},{11,17} };
static const GPathInfo s_unknown_paths[] = {
  { ARRAY_LENGTH(s_unknown_0_pts), (GPoint *)s_unknown_0_pts },
  { ARRAY_LENGTH(s_unknown_1_pts), (GPoint *)s_unknown_1_pts },
  { ARRAY_LENGTH(s_unknown_2_pts), (GPoint *)s_unknown_2_pts }
};

// ─────────────────────────────────────────────────────────────────────────────
// Master icon table
// ─────────────────────────────────────────────────────────────────────────────
static const WeatherIconDef s_weather_icons[GPATH_ID_COUNT] = {
  [GPATH_ID_CLOUDY_DAY]          = { 23, 14, 2,  s_cloudy_day_paths },
  [GPATH_ID_THUNDERSTORM]        = { 23, 18, 4,  s_thunderstorm_paths },
  [GPATH_ID_HEAVY_RAIN]          = { 23, 22, 5,  s_heavy_rain_paths },
  [GPATH_ID_HEAVY_SNOW]          = { 23, 23, 8,  s_heavy_snow_paths },
  [GPATH_ID_LIGHT_RAIN]          = { 23, 23, 6,  s_light_rain_paths },
  [GPATH_ID_LIGHT_SNOW]          = { 23, 23, 6,  s_light_snow_paths },
  [GPATH_ID_RAINING_AND_SNOWING] = { 23, 23, 6,  s_rain_snow_paths },
  [GPATH_ID_PARTLY_CLOUDY]       = { 23, 24, 8,  s_partly_cloudy_paths },
  [GPATH_ID_TIMELINE_SUN]        = { 22, 23, 9,  s_timeline_sun_paths },
  [GPATH_ID_TIMELINE_MOON]       = { 15, 22, 1,  s_timeline_moon_paths },
  [GPATH_ID_PARTLY_CLOUDY_NIGHT] = { 23, 23, 3,  s_partly_cloudy_night_paths },
  [GPATH_ID_UNKNOWN]             = { 22, 22, 3,  s_unknown_paths }
};

// ─────────────────────────────────────────────────────────────────────────────
// Icon code → GPath ID mapping
// ─────────────────────────────────────────────────────────────────────────────
#define ICON_UNKNOWN          0
#define ICON_UNDEFINED        1
#define ICON_CLEAR            2
#define ICON_CLEAR_N          3
#define ICON_PARTLY_CLOUDY    4
#define ICON_PARTLY_CLOUDY_N  5
#define ICON_MOSTLY_CLOUDY    6
#define ICON_MOSTLY_CLOUDY_N  7
#define ICON_CLOUDY           8
#define ICON_CLOUDY_N         9
#define ICON_CHANCE_FLURRIES  10
#define ICON_FLURRIES         11
#define ICON_CHANCE_FLURRIES_N 12
#define ICON_FLURRIES_N       13
#define ICON_CHANCE_RAIN      14
#define ICON_RAIN             15
#define ICON_CHANCE_RAIN_N    16
#define ICON_RAIN_N           17
#define ICON_CHANCE_SLEET     18
#define ICON_SLEET            19
#define ICON_CHANCE_SLEET_N   20
#define ICON_SLEET_N          21
#define ICON_CHANCE_SNOW      22
#define ICON_SNOW             23
#define ICON_CHANCE_SNOW_N    24
#define ICON_SNOW_N           25
#define ICON_CHANCE_TSTORMS   26
#define ICON_TSTORMS          27
#define ICON_CHANCE_TSTORMS_N 28
#define ICON_TSTORMS_N        29
#define ICON_FOG              30
#define ICON_HAZE             31
#define ICON_FOG_N            32
#define ICON_HAZE_N           33

static inline GPathIconID icon_code_to_gpath(int icon_code) {
  switch (icon_code) {
    case ICON_CLEAR:
    case ICON_PARTLY_CLOUDY:
      return GPATH_ID_TIMELINE_SUN;

    case ICON_CLEAR_N:
    case ICON_PARTLY_CLOUDY_N:
    case ICON_MOSTLY_CLOUDY_N:
    case ICON_CLOUDY_N:
      return GPATH_ID_TIMELINE_MOON;

    case ICON_MOSTLY_CLOUDY:
      return GPATH_ID_PARTLY_CLOUDY;

    case ICON_CLOUDY:
    case ICON_FOG:
    case ICON_FOG_N:
    case ICON_HAZE:
    case ICON_HAZE_N:
      return GPATH_ID_CLOUDY_DAY;

    case ICON_CHANCE_RAIN:
    case ICON_CHANCE_RAIN_N:
      return GPATH_ID_LIGHT_RAIN;

    case ICON_RAIN:
    case ICON_RAIN_N:
      return GPATH_ID_HEAVY_RAIN;

    case ICON_CHANCE_SNOW:
    case ICON_SNOW:
    case ICON_CHANCE_SNOW_N:
    case ICON_SNOW_N:
    case ICON_CHANCE_FLURRIES:
    case ICON_FLURRIES:
    case ICON_CHANCE_FLURRIES_N:
    case ICON_FLURRIES_N:
    case ICON_CHANCE_SLEET:
    case ICON_SLEET:
    case ICON_CHANCE_SLEET_N:
    case ICON_SLEET_N:
      return GPATH_ID_HEAVY_SNOW;

    case ICON_CHANCE_TSTORMS:
    case ICON_TSTORMS:
    case ICON_CHANCE_TSTORMS_N:
    case ICON_TSTORMS_N:
      return GPATH_ID_THUNDERSTORM;

    default:
      return GPATH_ID_UNKNOWN;
  }
}

// Draw a weather icon at (ox, oy) scaled to sz×sz, using the given color
static void draw_weather_icon(GContext *ctx, GPathIconID icon_id, int ox, int oy, int sz, GColor color) {
  if (icon_id >= GPATH_ID_COUNT) return;
  const WeatherIconDef *def = &s_weather_icons[icon_id];
  int native_max = def->native_w > def->native_h ? def->native_w : def->native_h;
  if (native_max == 0) return;
  int scale256 = (sz * 256) / native_max;

  graphics_context_set_stroke_color(ctx, color);
  graphics_context_set_stroke_width(ctx, 1);

  for (int p = 0; p < def->num_paths; p++) {
    const GPathInfo *pi = &def->paths[p];
    for (int i = 0; i < (int)pi->num_points - 1; i++) {
      GPoint a = GPoint(ox + (pi->points[i].x   * scale256) / 256,
                        oy + (pi->points[i].y   * scale256) / 256);
      GPoint b = GPoint(ox + (pi->points[i+1].x * scale256) / 256,
                        oy + (pi->points[i+1].y * scale256) / 256);
      graphics_draw_line(ctx, a, b);
    }
  }
}

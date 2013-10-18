#ifndef common_h
#define common_h

#include "pebble_os.h"

#define RECONNECT_KEY 0
#define REQUEST_CALENDAR_KEY 1
#define CLOCK_STYLE_KEY 2
#define CALENDAR_RESPONSE_KEY 3
#define REQUEST_BATTERY_KEY 8
#define BATTERY_RESPONSE_KEY 9
#define ALERT_EVENT 100
#define RESTORE_DATE 201
#define SECOND_ALERT 202
	
#define ROTATE_EVENT 203

#define CLOCK_STYLE_12H 1
#define CLOCK_STYLE_24H 2
	
#define MAX_EVENTS 15
	
#define STATUS_REQUEST 1
#define STATUS_REPLY 2
#define STATUS_ALERT_SET 3
	
#define	MAX_ALLOWABLE_ALERTS 10

typedef struct {
  uint8_t index;
  char title[21];
  bool has_location;
  char location[21];
  bool all_day;
  char start_date[18];
  int32_t alarms[2];
} Event;

typedef struct {
  uint8_t state;
  int8_t level;
} BatteryStatus;

typedef struct {
  char date[6];
  char dayName[10];
} CloseDay;

typedef struct {
  AppTimerHandle handle;
  char event_desc[21];
  bool active;
  char relative_desc[21]; 
  char location[21];
} TimerRecord;

#define REQUEST_BATTERY_INTERVAL_MS 120007
#define REQUEST_CALENDAR_INTERVAL_MS 600003
#define ROTATE_EVENT_INTERVAL_MS 3005
#define ROTATE_EVENT_INTERVAL_OVERNIGHT_MS 10005

#define OVERNIGHT_START 0
#define OVERNIGHT_END 6
	
#define TODAY "Today"
#define TOMORROW "Tomorrow"
#define ALL_DAY "All day"
	
void time_plus_day(PblTm *time, int daysToAdvance);
bool is_overnight();
void calendar_init(AppContextRef ctx);
void handle_calendar_timer(AppContextRef app_ctx, AppTimerHandle handle, uint32_t cookie);
void draw_date();
void received_message(DictionaryIterator *received, void *context);
void set_status(int new_status_display);
void set_event_display(char *event_title, char *event_start_date, char *location, int num);
void set_battery(uint8_t state, int8_t level);

#endif

export interface BrollySettings {
  // Appearance
  KEY_NUMBER_FONT: number          // 0=Digital 1=Standard 2=Traditional 3=Thin 4=Oversize
  KEY_DISPLAY_HOUR_MARKERS: number // 0|1
  KEY_DISPLAY_MINOR_MARKERS: number
  KEY_NUMBER_SIZE: number          // 1–5
  KEY_ICON_SIZE: number            // 1–5
  // Background
  KEY_BACKGROUND_COLOR: number
  // Hour hand
  KEY_HOUR_HAND_OUTER: number
  KEY_HOUR_HAND_INNER: number
  // Minute hand
  KEY_MIN_HAND_OUTER: number
  KEY_MIN_HAND_INNER: number
  // Seconds hand
  KEY_SECONDS_HAND_COLOR: number
  KEY_SECONDS_HAND_MODE: number    // 0=Never 1=Always 2=Shake
  KEY_SECONDS_SHAKE_DUR: number    // 5|10|15|30
  // Markers / numbers / icons colours
  KEY_HOUR_MARKER_COLOR: number
  KEY_MINUTE_MARKER_COLOR: number
  KEY_NUMBER_COLOR: number
  KEY_ICON_COLOR: number
  // Weather
  KEY_SHAKE_MODE: number           // 0=Shake 1=Always 2=Hide
  KEY_CUSTOM_LOCATION: string
  // Date / temp
  KEY_DATE_VISIBLE: number         // 0=Always 1=Off 2=Shake
  KEY_TEMP_VISIBLE: number
  KEY_DISPLAY_MODE: number         // 0=Both 1=Temp 2=Date 3=None
  KEY_TEMP_UNIT: number            // 0=C 1=F
  KEY_DATE_COLOR: number
  KEY_TEMP_COLOR: number
  // Sunrise/sunset
  KEY_SUNRISE_MARKER_VISIBLE: number  // 0=Always 1=Icons 2=Off
  KEY_SUNRISE_MARKER_COLOR: number
  KEY_SUNSET_MARKER_COLOR: number
  // Bluetooth
  KEY_VIBRATE_BT_DISCONNECT: number
  KEY_VIBRATE_BT_RECONNECT: number
  KEY_BT_DISCONNECT_MIN_INNER_RED: number
  KEY_BT_DISCONNECT_OUTER_COLOR: number
  KEY_BT_DISCONNECT_INNER_COLOR: number
  // Battery
  KEY_BATTERY_RING_THRESHOLD: number    // 0=off,50,40,30,20,10
  KEY_BATTERY_CENTER_THRESHOLD: number  // 0=off,20,10,5
}

export const DEFAULTS: BrollySettings = {
  KEY_NUMBER_FONT: 0,
  KEY_DISPLAY_HOUR_MARKERS: 1,
  KEY_DISPLAY_MINOR_MARKERS: 1,
  KEY_NUMBER_SIZE: 3,
  KEY_ICON_SIZE: 3,
  KEY_BACKGROUND_COLOR: 0x000000,
  KEY_HOUR_HAND_OUTER: 0xffffff,
  KEY_HOUR_HAND_INNER: 0x000000,
  KEY_MIN_HAND_OUTER: 0x000000,
  KEY_MIN_HAND_INNER: 0x0055ff,   // nearest Pebble to 0x0061fe
  KEY_SECONDS_HAND_COLOR: 0xffffff,
  KEY_SECONDS_HAND_MODE: 2,
  KEY_SECONDS_SHAKE_DUR: 10,
  KEY_HOUR_MARKER_COLOR: 0xffffff,
  KEY_MINUTE_MARKER_COLOR: 0x5555aa, // nearest Pebble to 0x6b7f99
  KEY_NUMBER_COLOR: 0xffffff,
  KEY_ICON_COLOR: 0xffffff,
  KEY_SHAKE_MODE: 0,
  KEY_CUSTOM_LOCATION: '',
  KEY_DATE_VISIBLE: 0,
  KEY_TEMP_VISIBLE: 0,
  KEY_DISPLAY_MODE: 0,
  KEY_TEMP_UNIT: 0,
  KEY_DATE_COLOR: 0x5555aa,        // nearest Pebble to 0x4a5f7f
  KEY_TEMP_COLOR: 0x5555aa,
  KEY_SUNRISE_MARKER_VISIBLE: 0,
  KEY_SUNRISE_MARKER_COLOR: 0xffaa00, // nearest Pebble to 0xff9500
  KEY_SUNSET_MARKER_COLOR: 0x0055ff,  // nearest Pebble to 0x0061fe
  KEY_VIBRATE_BT_DISCONNECT: 1,
  KEY_VIBRATE_BT_RECONNECT: 0,
  KEY_BT_DISCONNECT_MIN_INNER_RED: 1,
  KEY_BT_DISCONNECT_OUTER_COLOR: 0xff0000,
  KEY_BT_DISCONNECT_INNER_COLOR: 0xff0000,
  KEY_BATTERY_RING_THRESHOLD: 50,
  KEY_BATTERY_CENTER_THRESHOLD: 20,
}

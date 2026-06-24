import React, { useState, useEffect } from 'react'
import { PebbleColorPicker } from './PebbleColorPicker'
import { BrollySettings, DEFAULTS } from './defaults'

// ─────────────────────────────────────────────────────────────────────────────
// URL param helpers
// ─────────────────────────────────────────────────────────────────────────────
function loadFromUrl(): Partial<BrollySettings> {
  const params = new URLSearchParams(window.location.search)
  const out: Partial<BrollySettings> = {}
  params.forEach((val, key) => {
    if (key === 'KEY_CUSTOM_LOCATION') {
      (out as Record<string, unknown>)[key] = val
    } else {
      const n = parseInt(val, 10)
      if (!isNaN(n)) (out as Record<string, unknown>)[key] = n
    }
  })
  return out
}

function loadFromStorage(): Partial<BrollySettings> {
  try {
    const raw = localStorage.getItem('brolly_settings')
    if (raw) return JSON.parse(raw)
  } catch { /* ignore */ }
  return {}
}

function saveToStorage(s: BrollySettings) {
  try { localStorage.setItem('brolly_settings', JSON.stringify(s)) } catch { /* ignore */ }
}

// ─────────────────────────────────────────────────────────────────────────────
// Toggle component
// ─────────────────────────────────────────────────────────────────────────────
function Toggle({ label, value, onChange }: { label: string; value: boolean; onChange: (v: boolean) => void }) {
  return (
    <div className="row">
      <span className="row-label">{label}</span>
      <label className="toggle">
        <input type="checkbox" checked={value} onChange={e => onChange(e.target.checked)} />
        <span className="toggle-slider" />
      </label>
    </div>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Select row
// ─────────────────────────────────────────────────────────────────────────────
function SelectRow({ label, value, options, onChange }:
  { label: string; value: number; options: { label: string; value: number }[]; onChange: (v: number) => void }) {
  return (
    <div className="row">
      <span className="row-label">{label}</span>
      <select value={value} onChange={e => onChange(parseInt(e.target.value, 10))}>
        {options.map(o => <option key={o.value} value={o.value}>{o.label}</option>)}
      </select>
    </div>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Slider row
// ─────────────────────────────────────────────────────────────────────────────
function SliderRow({ label, value, min, max, onChange }:
  { label: string; value: number; min: number; max: number; onChange: (v: number) => void }) {
  return (
    <div className="row">
      <span className="row-label">{label}</span>
      <div className="slider-row">
        <input type="range" min={min} max={max} value={value}
          onChange={e => onChange(parseInt(e.target.value, 10))} />
        <span className="slider-val">{value}</span>
      </div>
    </div>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Section wrapper
// ─────────────────────────────────────────────────────────────────────────────
function Section({ title, children }: { title: string; children: React.ReactNode }) {
  return (
    <div className="section">
      <div className="section-title">{title}</div>
      {children}
    </div>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Tab 1: Appearance
// ─────────────────────────────────────────────────────────────────────────────
function AppearanceTab({ s, set }: { s: BrollySettings; set: (k: keyof BrollySettings, v: unknown) => void }) {
  return (
    <>
      <Section title="Appearance">
        <SelectRow label="Number font" value={s.KEY_NUMBER_FONT}
          options={[
            { label: 'Digital', value: 0 },
            { label: 'Standard', value: 1 },
            { label: 'Traditional', value: 2 },
            { label: 'Thin', value: 3 },
            { label: 'Oversize', value: 4 },
          ]}
          onChange={v => set('KEY_NUMBER_FONT', v)} />
        <Toggle label="Hour markers" value={!!s.KEY_DISPLAY_HOUR_MARKERS}
          onChange={v => set('KEY_DISPLAY_HOUR_MARKERS', v ? 1 : 0)} />
        <Toggle label="Minute markers" value={!!s.KEY_DISPLAY_MINOR_MARKERS}
          onChange={v => set('KEY_DISPLAY_MINOR_MARKERS', v ? 1 : 0)} />
        <SliderRow label="Number font size" value={s.KEY_NUMBER_SIZE} min={1} max={5}
          onChange={v => set('KEY_NUMBER_SIZE', v)} />
        <SliderRow label="Icon size" value={s.KEY_ICON_SIZE} min={1} max={5}
          onChange={v => set('KEY_ICON_SIZE', v)} />
      </Section>

      <Section title="Background">
        <PebbleColorPicker label="Background colour" value={s.KEY_BACKGROUND_COLOR}
          onChange={v => set('KEY_BACKGROUND_COLOR', v)} />
      </Section>

      <Section title="Watch Hands — Hour">
        <PebbleColorPicker label="Outer colour" value={s.KEY_HOUR_HAND_OUTER}
          onChange={v => set('KEY_HOUR_HAND_OUTER', v)} />
        <PebbleColorPicker label="Inner stripe" value={s.KEY_HOUR_HAND_INNER}
          onChange={v => set('KEY_HOUR_HAND_INNER', v)} />
      </Section>

      <Section title="Watch Hands — Minute">
        <PebbleColorPicker label="Outer colour" value={s.KEY_MIN_HAND_OUTER}
          onChange={v => set('KEY_MIN_HAND_OUTER', v)} />
        <PebbleColorPicker label="Inner stripe" value={s.KEY_MIN_HAND_INNER}
          onChange={v => set('KEY_MIN_HAND_INNER', v)} />
      </Section>

      <Section title="Watch Hands — Seconds">
        <PebbleColorPicker label="Colour" value={s.KEY_SECONDS_HAND_COLOR}
          onChange={v => set('KEY_SECONDS_HAND_COLOR', v)} />
        <SelectRow label="Visibility" value={s.KEY_SECONDS_HAND_MODE}
          options={[
            { label: 'Never', value: 0 },
            { label: 'Always', value: 1 },
            { label: 'Shake to show', value: 2 },
          ]}
          onChange={v => set('KEY_SECONDS_HAND_MODE', v)} />
        <SelectRow label="Shake duration" value={s.KEY_SECONDS_SHAKE_DUR}
          options={[
            { label: '5s', value: 5 },
            { label: '10s', value: 10 },
            { label: '15s', value: 15 },
            { label: '30s', value: 30 },
          ]}
          onChange={v => set('KEY_SECONDS_SHAKE_DUR', v)} />
      </Section>

      <Section title="Markers, Numbers &amp; Icons">
        <PebbleColorPicker label="Hour marker colour" value={s.KEY_HOUR_MARKER_COLOR}
          onChange={v => set('KEY_HOUR_MARKER_COLOR', v)} />
        <PebbleColorPicker label="Minute marker colour" value={s.KEY_MINUTE_MARKER_COLOR}
          onChange={v => set('KEY_MINUTE_MARKER_COLOR', v)} />
        <PebbleColorPicker label="Number colour" value={s.KEY_NUMBER_COLOR}
          onChange={v => set('KEY_NUMBER_COLOR', v)} />
        <PebbleColorPicker label="Icon colour" value={s.KEY_ICON_COLOR}
          onChange={v => set('KEY_ICON_COLOR', v)} />
      </Section>
    </>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Tab 2: Weather
// ─────────────────────────────────────────────────────────────────────────────
function WeatherTab({ s, set }: { s: BrollySettings; set: (k: keyof BrollySettings, v: unknown) => void }) {
  return (
    <>
      <Section title="Weather Visibility">
        <SelectRow label="Weather icons" value={s.KEY_SHAKE_MODE}
          options={[
            { label: 'Show on shake', value: 0 },
            { label: 'Always show', value: 1 },
            { label: 'Always hide', value: 2 },
          ]}
          onChange={v => set('KEY_SHAKE_MODE', v)} />
      </Section>

      <Section title="Location">
        <div className="row full-row">
          <span className="row-label">Custom location</span>
          <input
            type="text"
            placeholder="City name or lat,lon (leave empty for GPS)"
            value={s.KEY_CUSTOM_LOCATION}
            onChange={e => set('KEY_CUSTOM_LOCATION', e.target.value)}
          />
        </div>
      </Section>

      <Section title="Date and Temperature">
        <SelectRow label="Visibility" value={s.KEY_DATE_VISIBLE}
          options={[
            { label: 'Always show', value: 0 },
            { label: 'Show on shake', value: 2 },
            { label: 'Always hide', value: 1 },
          ]}
          onChange={v => { set('KEY_DATE_VISIBLE', v); set('KEY_TEMP_VISIBLE', v) }} />
        <SelectRow label="Display" value={s.KEY_DISPLAY_MODE}
          options={[
            { label: 'Date & Temperature', value: 0 },
            { label: 'Temperature only', value: 1 },
            { label: 'Date only', value: 2 },
            { label: 'None', value: 3 },
          ]}
          onChange={v => set('KEY_DISPLAY_MODE', v)} />
        <SelectRow label="Temperature unit" value={s.KEY_TEMP_UNIT}
          options={[
            { label: '°C', value: 0 },
            { label: '°F', value: 1 },
          ]}
          onChange={v => set('KEY_TEMP_UNIT', v)} />
        <PebbleColorPicker label="Date colour" value={s.KEY_DATE_COLOR}
          onChange={v => set('KEY_DATE_COLOR', v)} />
        <PebbleColorPicker label="Temperature colour" value={s.KEY_TEMP_COLOR}
          onChange={v => set('KEY_TEMP_COLOR', v)} />
      </Section>

      <Section title="Sunrise / Sunset">
        <SelectRow label="Sunrise/Sunset markers" value={s.KEY_SUNRISE_MARKER_VISIBLE}
          options={[
            { label: 'Always show', value: 0 },
            { label: 'Show with icons', value: 1 },
            { label: 'Off', value: 2 },
          ]}
          onChange={v => set('KEY_SUNRISE_MARKER_VISIBLE', v)} />
        <PebbleColorPicker label="Sunrise marker colour" value={s.KEY_SUNRISE_MARKER_COLOR}
          onChange={v => set('KEY_SUNRISE_MARKER_COLOR', v)} />
        <PebbleColorPicker label="Sunset marker colour" value={s.KEY_SUNSET_MARKER_COLOR}
          onChange={v => set('KEY_SUNSET_MARKER_COLOR', v)} />
      </Section>
    </>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Tab 3: Alerts
// ─────────────────────────────────────────────────────────────────────────────
function AlertsTab({
  s, set, onTestBattery, onTestBT
}: {
  s: BrollySettings
  set: (k: keyof BrollySettings, v: unknown) => void
  onTestBattery: () => void
  onTestBT: () => void
}) {
  return (
    <>
      <Section title="Bluetooth">
        <Toggle label="Vibrate on disconnect" value={!!s.KEY_VIBRATE_BT_DISCONNECT}
          onChange={v => set('KEY_VIBRATE_BT_DISCONNECT', v ? 1 : 0)} />
        <Toggle label="Vibrate on reconnect" value={!!s.KEY_VIBRATE_BT_RECONNECT}
          onChange={v => set('KEY_VIBRATE_BT_RECONNECT', v ? 1 : 0)} />
        <Toggle label="Change minute hand on disconnect" value={!!s.KEY_BT_DISCONNECT_MIN_INNER_RED}
          onChange={v => set('KEY_BT_DISCONNECT_MIN_INNER_RED', v ? 1 : 0)} />
        <PebbleColorPicker label="Disconnect outer colour" value={s.KEY_BT_DISCONNECT_OUTER_COLOR}
          onChange={v => set('KEY_BT_DISCONNECT_OUTER_COLOR', v)} />
        <PebbleColorPicker label="Disconnect inner colour" value={s.KEY_BT_DISCONNECT_INNER_COLOR}
          onChange={v => set('KEY_BT_DISCONNECT_INNER_COLOR', v)} />
      </Section>

      <Section title="Centre Cap — Battery">
        <SelectRow label="Outer ring alert threshold" value={s.KEY_BATTERY_RING_THRESHOLD}
          options={[
            { label: 'Off', value: 0 },
            { label: '50%', value: 50 },
            { label: '40%', value: 40 },
            { label: '30%', value: 30 },
            { label: '20%', value: 20 },
            { label: '10%', value: 10 },
          ]}
          onChange={v => set('KEY_BATTERY_RING_THRESHOLD', v)} />
        <SelectRow label="Centre dot alert threshold" value={s.KEY_BATTERY_CENTER_THRESHOLD}
          options={[
            { label: 'Off', value: 0 },
            { label: '20%', value: 20 },
            { label: '10%', value: 10 },
            { label: '5%', value: 5 },
          ]}
          onChange={v => set('KEY_BATTERY_CENTER_THRESHOLD', v)} />
      </Section>

      <Section title="Test Buttons">
        <div className="row">
          <button className="btn-test" onClick={onTestBattery}>Test battery alert</button>
        </div>
        <div className="row">
          <button className="btn-test" onClick={onTestBT}>Test BT disconnect</button>
        </div>
      </Section>
    </>
  )
}

// ─────────────────────────────────────────────────────────────────────────────
// Main App
// ─────────────────────────────────────────────────────────────────────────────
export default function App() {
  const [tab, setTab] = useState(0)
  const [settings, setSettings] = useState<BrollySettings>(() => {
    const fromStorage = loadFromStorage()
    const fromUrl     = loadFromUrl()
    return { ...DEFAULTS, ...fromStorage, ...fromUrl }
  })

  // Persist to localStorage on every change
  useEffect(() => { saveToStorage(settings) }, [settings])

  function set(key: keyof BrollySettings, value: unknown) {
    setSettings(prev => ({ ...prev, [key]: value }))
  }

  function handleSave() {
    // Build payload — exclude string keys that need special handling
    const payload: Record<string, unknown> = {}
    for (const [k, v] of Object.entries(settings)) {
      payload[k] = v
    }
    const encoded = encodeURIComponent(JSON.stringify(payload))
    window.location.href = 'pebblejs://close#' + encoded
  }

  function handleCancel() {
    window.location.href = 'pebblejs://close'
  }

  function handleTestBattery() {
    const payload = JSON.stringify({ KEY_TEST_BATTERY_ALERT: 1 })
    window.location.href = 'pebblejs://close#' + encodeURIComponent(payload)
  }

  function handleTestBT() {
    const payload = JSON.stringify({ KEY_TEST_BT_DISCONNECT: 1 })
    window.location.href = 'pebblejs://close#' + encodeURIComponent(payload)
  }

  return (
    <div>
      <div className="tabs">
        {['Appearance', 'Weather', 'Alerts'].map((t, i) => (
          <button key={i} className={`tab-btn${tab === i ? ' active' : ''}`}
            onClick={() => setTab(i)}>{t}</button>
        ))}
      </div>

      <div style={{ paddingBottom: 70 }}>
        {tab === 0 && <AppearanceTab s={settings} set={set} />}
        {tab === 1 && <WeatherTab s={settings} set={set} />}
        {tab === 2 && <AlertsTab s={settings} set={set}
          onTestBattery={handleTestBattery} onTestBT={handleTestBT} />}
      </div>

      <div className="action-bar">
        <button className="btn-cancel" onClick={handleCancel}>Cancel</button>
        <button className="btn-save" onClick={handleSave}>Save</button>
      </div>
    </div>
  )
}

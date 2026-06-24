import React, { useState } from 'react'

// 64-colour Pebble palette (6-bit RGB: 2 bits per channel → 0x00, 0x55, 0xAA, 0xFF per channel)
const CHANNEL = [0x00, 0x55, 0xAA, 0xFF]

function buildPalette(): number[] {
  const palette: number[] = []
  for (const r of CHANNEL) {
    for (const g of CHANNEL) {
      for (const b of CHANNEL) {
        palette.push((r << 16) | (g << 8) | b)
      }
    }
  }
  return palette
}

const PALETTE = buildPalette()

function toHex(rgb: number): string {
  return '#' + rgb.toString(16).padStart(6, '0')
}

function snapToPebble(hex: string): number {
  // Parse hex to r,g,b
  const n = parseInt(hex.replace('#', ''), 16)
  const r = (n >> 16) & 0xFF
  const g = (n >> 8) & 0xFF
  const b = n & 0xFF

  // Find nearest Pebble colour
  let best = 0
  let bestDist = Infinity
  for (const p of PALETTE) {
    const pr = (p >> 16) & 0xFF
    const pg = (p >> 8) & 0xFF
    const pb = p & 0xFF
    const dist = (r - pr) ** 2 + (g - pg) ** 2 + (b - pb) ** 2
    if (dist < bestDist) { bestDist = dist; best = p }
  }
  return best
}

interface Props {
  label: string
  value: number   // 0xRRGGBB integer
  onChange: (val: number) => void
}

export function PebbleColorPicker({ label, value, onChange }: Props) {
  const [open, setOpen] = useState(false)

  return (
    <>
      <div className="row">
        <span className="row-label">{label}</span>
        <button
          className="color-swatch-btn"
          style={{ background: toHex(value) }}
          onClick={() => setOpen(true)}
          aria-label={`Pick colour for ${label}`}
        />
      </div>

      {open && (
        <div className="picker-overlay" onClick={() => setOpen(false)}>
          <div className="picker-modal" onClick={e => e.stopPropagation()}>
            <h3>{label}</h3>
            <div className="picker-grid">
              {PALETTE.map(c => (
                <button
                  key={c}
                  className={`picker-swatch${c === value ? ' selected' : ''}`}
                  style={{ background: toHex(c) }}
                  onClick={() => { onChange(c); setOpen(false) }}
                  title={toHex(c)}
                />
              ))}
            </div>
            <button className="picker-close" onClick={() => setOpen(false)}>Close</button>
          </div>
        </div>
      )}
    </>
  )
}

export { snapToPebble, toHex }

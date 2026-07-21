# 🏏 Cricket Tournament Points Table in C

A command-line Cricket Tournament Management System in C with **input validation**, **automatic point calculation**, and **ranked scorecard display**.

---

## 🚀 Quick Start

```bash
# Compile
gcc scorecard.c -o scorecard

# Run
./scorecard        # Linux / Mac
scorecard.exe      # Windows
```

> **Requirement:** GCC compiler
> - Linux: `sudo apt install gcc`
> - Mac: `xcode-select --install`
> - Windows: [MinGW](https://www.mingw-w64.org/)

---

## 🎮 How It Works

Step 1 → Enter number of teams
Step 2 → Enter maximum matches allowed per team
Step 3 → Enter match stats for each team
Step 4 → Program validates, calculates & sorts
Step 5 → Ranked points table is displayed

---

## 📊 Points System

| Result | Points |
|--------|--------|
| 🟢 Win  | 2 pts  |
| 🟡 Draw | 1 pt   |
| 🔴 Loss | 0 pts  |

---

## 🛡️ Validations

| Check | Error Message |
|-------|--------------|
| Max matches ≤ 0 | `Maximum matches must be greater than 0` |
| Negative values | `Negative values are not allowed` |
| Played > maxMatches | `Team has played more than allowed matches` |
| Won + Lost + Draw ≠ Played | `Invalid match data — values don't add up` |

---

## 💡 Sample Run

**Input:**
Enter number of teams: 3
Enter maximum matches allowed: 5
Enter Team 1 Name: India
Matches Played: 5
Matches Won: 4
Matches Lost: 0
Matches Draw: 1
Enter Team 2 Name: Australia
Matches Played: 5
Matches Won: 3
Matches Lost: 1
Matches Draw: 1
Enter Team 3 Name: England
Matches Played: 5
Matches Won: 1
Matches Lost: 3
Matches Draw: 1

**Output:**

====== CRICKET TOURNAMENT POINTS TABLE ======
Team            Played   Won    Lost   Draw   Points
India           5        4      0      1      9
Australia       5        3      1      1      7
England         5        1      3      1      3
Tournament completed successfully!

---

## ✅ Features

- **Dynamic team input** — supports any number of teams
- **Max match limit** — configurable per tournament
- **4-level input validation** — catches all bad inputs
- **Auto point calculation** — wins × 2 + draws × 1
- **Auto ranking** — sorted by points (highest first)
- **Clean table output** — aligned formatted display

---

## 📁 Project Structure
cricket-scorecard/
├── main.c          # Complete source code
|-- README.md       # Documentation   
└── Output.png      #Output image

---

## 🧠 Concepts Used

`Structs` · `Arrays` · `Loops` · `Bubble Sort` · `Input Validation` · `Formatted Output` · `VLAs`

---

## 🚧 Known Limitations

- Team names cannot contain spaces (`SriLanka` ✅ `Sri Lanka` ❌)
- No tie-breaker for equal points
- Results not saved after program exits

---

## 🔮 Planned Improvements

- [ ] Net Run Rate (NRR) as tie-breaker
- [ ] Export results to `.txt` file
- [ ] Support team names with spaces
- [ ] Color-coded terminal output
- [ ] Multiple tournament rounds

---

## 👩‍💻 Author

**Swati Swaroop** · B.Tech Student

*Built as a C programming practice project — structs, sorting, validation & formatted output.*

![C](https://img.shields.io/badge/Language-C-blue)
![GCC](https://img.shields.io/badge/Compiler-GCC-orange)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Mac%20%7C%20Windows-lightgrey)

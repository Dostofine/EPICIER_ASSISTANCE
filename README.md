# 🛒 EPICIER ASSISTANCE

A command-line grocery store price management system designed to help shopkeepers efficiently record, organize, and export pricing data.

## 📋 Overview

EPICIER ASSISTANCE is a C-based application that streamlines the process of recording product prices for grocery stores (épiciers). The system allows shopkeepers to quickly input prices, automatically generates organized records with timestamps, and exports data in multiple formats for easy analysis and record-keeping.

## ✨ Features

- **Price Entry System**: Quick and intuitive price recording interface
- **Automatic Data Organization**: Creates timestamped JSON files for each pricing session
- **Multiple Export Formats**: 
  - JSON files for structured data storage
  - TXT files for human-readable records
  - CSV files for spreadsheet compatibility
- **Interactive Menu**: User-friendly command-line interface with clear options
- **Data Persistence**: All records are automatically saved in organized directories

## 📁 Project Structure

```
EPICIER_ASSISTANCE/
├── SRC/                    # Source code files
├── include/                # Header files
├── data/
│   ├── json_files/        # JSON data storage
│   ├── txt_files/         # Text exports
│   └── csv_files/         # CSV exports
├── Makefile               # Build configuration
├── requirements.txt       # Dependencies (jq)
└── README.md
```

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make
- jq (JSON processor)

Install dependencies on Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install build-essential jq
```

### Installation

1. Clone the repository:
```bash
git clone https://github.com/Dostofine/EPICIER_ASSISTANCE.git
cd EPICIER_ASSISTANCE
```

2. Build the project:
```bash
make
```

3. Run the application:
```bash
./epicier_assistance
```

## 💻 Usage

### Main Menu Options

**N - Nouvelle Saisie (New Entry)**
- Enter prices one by one
- Input `0` to finish and save
- Automatically generates a timestamped JSON file in `data/json_files/`

**L - Lister (List)**
- Creates a TXT file in `data/txt_files/`
- Displays formatted data in the terminal
- Shows all recorded prices in a readable format

**E - Exporter CSV (Export CSV)**
- Generates CSV files in `data/csv_files/`
- Perfect for spreadsheet applications (Excel, LibreOffice)
- Easy data analysis and reporting

**Q - Quitter (Quit)**
- Exit the program safely

### Example Workflow

```bash
# Start the program
./epicier_assistance

# Select option N to enter new prices
# Enter prices: 12.50, 8.99, 15.00, 0 (to finish)
# Data saved automatically with current date

# Select option L to view records
# Review formatted output in terminal

# Select option E to export to CSV
# Open generated CSV in your spreadsheet application

# Select Q to quit
```

## 📊 Data Format

### JSON Files
Located in `data/json_files/` with format: `YYYY-MM-DD_HH-MM-SS.json`

### TXT Files
Human-readable format in `data/txt_files/`

### CSV Files
Spreadsheet-compatible exports in `data/csv_files/`

## 🛠️ Building from Source

```bash
# Clean previous builds
make clean

# Compile the project
make

# Run
make run
```

## 👨‍💻 Author

**Dostofine**

## 🎓 Academic Context

This project was developed as part of a university Semester 1 programming course, demonstrating practical applications of:
- C programming fundamentals

##  Acknowledgments

- Built with C for performance and efficiency
- Uses `jq` for JSON processing and validation
- Designed for real-world grocery store operations

---

**Note**: This is an educational project demonstrating practical programming skills in a commercial context.
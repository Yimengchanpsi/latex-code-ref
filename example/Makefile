# example/Makefile
#
# Builds the example PDF.
#
# Usage:
#   make          — scan sources, then compile LaTeX
#   make scan     — re-run the scanner only
#   make pdf      — compile LaTeX only (assumes coderef_defs.tex exists)
#   make clean    — remove generated and build artefacts

PYTHON   ?= python3
SCANNER  := ../scan_coderefs.py
SRC_DIR  := src
EXTS     := "*.cpp" "*.h" "*.py"

TEX_FILE  := main.tex
PDF_FILE  := main.pdf
DB_JSON   := coderef_db.json
DB_TEX    := coderef_defs.tex

.PHONY: all scan pdf clean

all: scan pdf

scan: $(DB_TEX)

$(DB_TEX): $(shell find $(SRC_DIR) -name '*.cpp' -o -name '*.h' -o -name '*.py')
	$(PYTHON) $(SCANNER) $(SRC_DIR) --extensions $(EXTS) \
	    --json-output $(DB_JSON) --latex-output $(DB_TEX)

pdf: $(DB_TEX)
	pdflatex $(TEX_FILE)
	pdflatex $(TEX_FILE)   # second pass for cross-references

clean:
	rm -f $(DB_JSON) $(DB_TEX) \
	      *.aux *.log *.out *.toc $(PDF_FILE)

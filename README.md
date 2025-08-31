# Protein Structure Analysis – Hyp_7

This project originates from an **original MATLAB procedure**, which has been rewritten in C++ to compare runtime efficiency between the two languages, given the complexity and volume of structural data. This project focuses on analyzing protein crystal structure using atomic coordinate lists, diffraction data, and supporting metadata. A lightweight C++ program is provided to transform atomic coordinates from Cartesian to fractional (with respect to the unit cell) using the GNU Scientific Library (GSL). Additional data files include atom–molecule mappings, hydrogen positions, diffraction reflections, and modulation coefficients.

---

## Repository Contents

### Source Code
- **main.cpp** – loads atomic lists, sets up the unit cell matrix (`a=b=146.29`, `c=42.6514`), inverts it using GSL, and converts Cartesian coordinates into fractional coordinates. Shows the expected column format in atomic lists (index, molecule ID, `x y z`, element flags, `prob`, `SOF`, `ADP`).

### Structural and Auxiliary Data
- **Structural_data.txt** – metadata file: reference PDB (`4N3E`), unit cell parameters (`a,b,c, α,β,γ`), symmetry group, and list of residues/elements.  
  *Note: contains `c=298.56`, while `main.cpp` uses `c=42.6514`. This discrepancy requires verification.*  
- **Lista_atomy_Hyp_7_reduced.txt** – reduced atomic list: `index`, `mol`, `x y z`, flags for `N C O S`, `prob`, `SOF`, `ADP`. Matches the `fscanf` format used in `main.cpp`.  
- **Wodory_Hyp_7.txt** – hydrogen atom list: index, molecule ID, occupancy, `x y z`.  
- **Lista_molekul_atom_index.txt** – mapping of molecule IDs to atom index ranges.  
- **Lista_molekul_hydrogen_index.txt** – mapping of molecule IDs to hydrogen index ranges.  

### Diffraction Data & Coefficients
- **diffraction_Hyp_7_1_sigma.txt** – diffraction reflections with indices (`h k l m`) and measured intensity/sigma values.  
- **coefficients_Hyp_7.txt** – sets of coefficients used for refinement/modeling (to be fully documented).  
- **modulated_example.txt** – example modulation data (index grids with paired numerical values), useful for superspace or modulation analysis.

---

## Quick Start

### Requirements
- **C++17** 
- **GSL** (GNU Scientific Library) + **CBLAS**



# Compiler settings for Visual Studio
CC = cl.exe
CFLAGS = /nologo /W4 /O2 /EHsc
LDFLAGS = 
EXESUFFIX = .exe

# Your three main source files (update these names)
SRC1 = 00_hello_world.c
SRC2 = 01_lgw.c    # Update with your actual filename
SRC3 = 02_stars.c    # Update with your actual filename
SRC4 = 03_sum.c    # Update with your actual filename
SRC5 = 04_sum_prod.c    # Update with your actual filename
SRC6 = 05_avrg.c    # Update with your actual filename

# Executable names (same as source files without .c extension)
EXEC1 = $(SRC1:.c=$(EXESUFFIX))
EXEC2 = $(SRC2:.c=$(EXESUFFIX))
EXEC3 = $(SRC3:.c=$(EXESUFFIX))
EXEC4 = $(SRC4:.c=$(EXESUFFIX))
EXEC5 = $(SRC5:.c=$(EXESUFFIX))
EXEC6 = $(SRC6:.c=$(EXESUFFIX))

# All executables
EXECS = $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5) $(EXEC6)

# Default target
all: $(EXECS)

# Build each executable
$(EXEC1): $(SRC1)
	$(CC) $(CFLAGS) $(LDFLAGS) /Fe$@ $**

$(EXEC2): $(SRC2)
	$(CC) $(CFLAGS) $(LDFLAGS) /Fe$@ $**

$(EXEC3): $(SRC3)
	$(CC) $(CFLAGS) $(LDFLAGS) /Fe$@ $**

$(EXEC4): $(SRC4)
	$(CC) $(CFLAGS) $(LDFLAGS) /Fe$@ $**

# Clean up
clean:
	del /Q $(EXECS) *.obj *.exe.manifest *.pdb 2>nul

# Phony targets
.PHONY: all clean
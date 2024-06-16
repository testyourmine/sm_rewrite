
#ifndef TRACING_H
#define TRACING_H

#include <stdbool.h>

#include "snes/snes.h"

void getProcessorStateCpu(Snes* snes, char* line);
void getProcessorStateSpc(Apu* snes, char* line);

#endif

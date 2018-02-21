#include <debug.h>
#include <plat_config.h>
#include <mmio.h>
#include <sys/errno.h>

#include "sunxi_def.h"
#include "sunxi_private.h"

int sunxi_setup_sensors(void)
{
	return 0;
}

const char* sunxi_sensor_get_name(int sensornr)
{
	switch(sensornr) {
	case 0: return "cpu_temp";
	case 1: return "gpu_temp";
	}

	return NULL;
}

uint32_t sunxi_sensor_get_value(int sensornr)
{
	switch(sensornr) {
	case 0:
	case 1:
		return sunxi_ths_read_temp(sensornr);
	}

	return ~0;
}

int sunxi_sensors_nr_sensors(void)
{
	return 2;
}

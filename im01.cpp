#include "pxt.h"
#include "mbed.h"
#include "SDFileSystem.h"
#include "MicroBit.h"

namespace im01
{
	//%
	void _mkdir(String s)
	{
		SDFileSystem sd(P0_21, P0_22, P0_23, P0_16, "sd");
		microbit_create_heap(MICROBIT_SD_GATT_TABLE_START + MICROBIT_SD_GATT_TABLE_SIZE, MICROBIT_SD_LIMIT);
		mkdir((const char *)s->getUTF8Data(), 0777);
	}


	//%
	bool _file(String s, String v, String x)
	{
		SDFileSystem sd(P0_21, P0_22, P0_23, P0_16, "sd");
		FILE *fp = fopen((const char *)s->getUTF8Data(), (const char *)x->getUTF8Data());
		if (fp == NULL)
			return false;

		fprintf(fp, (const char *)v->getUTF8Data());
		fclose(fp);
		return true;
	}

} // namespace im01
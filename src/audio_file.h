#include <stdio.h>

struct audio_format;

struct audio_file {
	FILE *fp;

	struct audio_format *drv;
	void *drv_data;
	unsigned int srate;
	unsigned int channels;
	unsigned int time_len;
	unsigned int time_cur;
	int stream;
	char *artist;
	char *title;
};

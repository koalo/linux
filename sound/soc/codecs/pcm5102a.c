/*
 * Driver for the PCM5102A codec
 * It is a dummy driver without any controls.
 *
 * Copyright 2013
 * Author: Francesco Valla <valla.francesco@gmail.com>
 * Based on ess9018.c by Florian Meier <koalo@koalo.de>
 * 
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

#include <sound/soc.h>

static struct snd_soc_dai_driver pcm5102a_dai = {
	.name = "pcm5102a-hifi",
	.playback = {
		.channels_min = 1,
		.channels_max = 2,
		.rates = SNDRV_PCM_RATE_8000_192000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32_LE
	},
};

static struct snd_soc_codec_driver soc_codec_dev_pcm5102a;

static int pcm5102a_probe(struct platform_device *pdev)
{
	return snd_soc_register_codec(&pdev->dev, &soc_codec_dev_pcm5102a,
			&pcm5102a_dai, 1);
}

static int pcm5102a_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);

	return 0;
}

static struct platform_driver pcm5102a_codec_driver = {
	.probe 		= pcm5102a_probe,
	.remove 	= pcm5102a_remove,
	.driver		= {
		.name	= "pcm5102a-codec",
		.owner	= THIS_MODULE,
	},
};

module_platform_driver(pcm5102a_codec_driver);

MODULE_AUTHOR("Francesco Valla <valla.francesco@gmail.com>");
MODULE_DESCRIPTION("ASoC PCM5102A codec driver");
MODULE_LICENSE("GPL");


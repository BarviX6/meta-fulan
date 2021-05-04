ENIGMA2_PLUGINS_append_sh4 += "\
	kernel-module-block2mtd libcrypto \
	"

ENIGMA2_PLUGINS_append_spark7162 += "\
	"


ENIGMA2_PLUGINS_remove += "\
	"

# Add enigma2-plugin-extensions-openwebif-extras to replace enigma2-plugin-extensions-openwebif
# Ship some extra stuff with the image like youtube, serviceapp, iptvplayer etc..
ENIGMA2_PLUGINS_append += "\
	enigma2-plugin-extensions-cacheflush \
    enigma2-plugin-extensions-dreamexplorer \
	enigma2-plugin-extensions-e2iplayer \
	enigma2-plugin-extensions-e2iplayer-deps \
	enigma2-plugin-extensions-youtube \
    enigma2-plugin-extensions-permanentclock \
    enigma2-plugin-extensions-sparkvfd \
	enigma2-plugin-softcams-oscam \
	enigma2-plugin-softcams-oscam-emu \
	"





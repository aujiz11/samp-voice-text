/*
	SA-MP Voice Text Speech - a library with a simple command structure
	Author: Ausil 

	If there is a problem, please report it in the "Issues" section on github.

	0 - Vietnamese | 1 - English
*/
#if defined _included_voice_text
	#endinput
#endif

#define _included_voice_text

/* LIBRARIES */
#include <a_samp>
#include <YSI_Data\y_foreach>

/* FUNCTION */
stock SendVoicePlayer(playerid, const szMsg[], language = 0)
{
	new
		szUrl[360];
	
	if(language) format(szUrl, sizeof(szUrl), "https://translate.google.com/translate_tts?ie=UTF-8&tl=en-us&client=tw-ob&q=%s", szMsg);
	else format(szUrl, sizeof(szUrl), "https://translate.google.com/translate_tts?ie=UTF-8&tl=vi&client=tw-ob&q=%s", szMsg);

	return PlayAudioStreamForPlayer(playerid, szUrl);
}

stock SendVoiceAll(const szMsg[], language = 0)
{
	new
		szUrl[360];
	if(language) format(szUrl, sizeof(szUrl), "https://translate.google.com/translate_tts?ie=UTF-8&tl=en-us&client=tw-ob&q=%s", szMsg);
	else format(szUrl, sizeof(szUrl), "https://translate.google.com/translate_tts?ie=UTF-8&tl=vi&client=tw-ob&q=%s", szMsg);

	foreach(new i: Player)
	{
		PlayAudioStreamForPlayer(i, szUrl);
	}
	return 1;
}

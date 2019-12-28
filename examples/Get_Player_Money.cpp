int GetPlayerMoney(){
	int money;
	g_pEsp->ReadInt((LPCVOID*)(entityBase + g_pOffsets->m_bHasHelmet - 8), &money);
	return money;
}

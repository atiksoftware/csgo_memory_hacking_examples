bool GetPlayerIsDefusing(){
	bool isDefusing;
	g_pEsp->ReadBool((LPCVOID*)(entityPoint + g_pOffsets->m_bIsDefusing), &isDefusing);
	return isDefusing;
}

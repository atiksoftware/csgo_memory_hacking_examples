bool GetPlayerHasDefuser(){
	bool hasDefuser;
	g_pEsp->ReadBool((LPCVOID*)(entityPoint + g_pOffsets->m_bHasDefuser), &hasDefuser);
	return hasDefuser;
}

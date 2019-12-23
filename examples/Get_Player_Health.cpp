int GetPlayerHealth(){
	int health;
	g_pEsp->ReadInt((LPCVOID*)(entityPoint + g_pEsp->m_iHealth), &health); 
	return health;
}

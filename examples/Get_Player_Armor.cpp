int GetPlayerArmor(){ 
	int armor;
	g_pEsp->ReadInt((LPCVOID*)(entityPoint + g_pEsp->m_ArmorValue), &armor);
	return armor;
}

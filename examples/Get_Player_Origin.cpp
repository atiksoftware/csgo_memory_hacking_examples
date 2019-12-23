Vector3 GetPlayerOrigin(){
	Vector3 origin;
	g_pEsp->ReadBytes((LPCVOID*)(entityPoint + g_pEsp->m_vecOrigin), 12, &origin);
	return origin;
}

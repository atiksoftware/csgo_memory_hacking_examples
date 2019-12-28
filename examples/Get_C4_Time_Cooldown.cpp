float Get_C4_CountDown(){
	// C4 total seconds, its default 40 seconds
	// C4 toplam süresi, default olarak 40 saniye
	float C4_TimerLength;
	g_pEsp->ReadFloat((LPCVOID*)(entityPoint + g_pOffsets->m_flTimerLength), &C4_TimerLength);
	
	// C4 current time, it can change while time forward. you can see as like 3850
	// C4 geçerli zamanı, oyun ilerledikçe değişiklik gösterbilir. 3850 gibi bir rakam görebilirsin.
	float C4_CurrentTime;
	g_pEsp->ReadFloat((LPCVOID*)(entityPoint + g_pOffsets->m_flLastBoneSetupTime), &C4_CurrentTime);
	
	// C4 end time. it also can change like C4_CurrentTime. but it more as total time
	// C4 bitiş süresi. bu da C4_CurrentTime gibi değişir. fakat toplam süre kadar ileridir.
	float C4_EndTime;
	g_pEsp->ReadFloat((LPCVOID*)(entityPoint + g_pOffsets->m_flC4Blow), &C4_EndTime);
	
	return C4_EndTime - C4_CurrentTime;
}

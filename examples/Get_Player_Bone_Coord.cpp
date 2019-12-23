Vector3 GetPlayerBoneCoord(int boneId){
	float vecBone[3];
	DWORD plr_bone_matrix;
	g_pEsp->ReadDword((LPCVOID*)(entityPoint + g_pEsp->m_dwBoneMatrix), &plr_bone_matrix);
	g_pEsp->ReadFloat((LPCVOID*)(plr_bone_matrix + 0x30 * boneId + 0x0C), &vecBone[0]);
	g_pEsp->ReadFloat((LPCVOID*)(plr_bone_matrix + 0x30 * boneId + 0x1C), &vecBone[1]);
	g_pEsp->ReadFloat((LPCVOID*)(plr_bone_matrix + 0x30 * boneId + 0x2C), &vecBone[2]);
	Vector3 coord = { vecBone[0],vecBone[1],vecBone[2] };
	return coord;
}

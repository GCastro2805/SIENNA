#pragma once


// Cuadro de di�logo de CRegistro

class CRegistro : public CDialog
{
	DECLARE_DYNAMIC(CRegistro)

public:
	CRegistro(CWnd* pParent = NULL);   // Constructor est�ndar
	virtual ~CRegistro();

// Datos del cuadro de di�logo
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
};

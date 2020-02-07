#pragma once


// Cuadro de diálogo de CRegistro

class CRegistro : public CDialog
{
	DECLARE_DYNAMIC(CRegistro)

public:
	CRegistro(CWnd* pParent = NULL);   // Constructor estándar
	virtual ~CRegistro();

// Datos del cuadro de diálogo
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
};

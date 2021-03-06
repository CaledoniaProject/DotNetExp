#pragma once
#include "TreeNodeBase.h"
#include "DataTarget.h"

class AssembliesTreeNode : public TreeNodeBase {
public:
	AssembliesTreeNode(CTreeItem item, DataTarget* dt, CLRDATA_ADDRESS ad);

private:
	// Inherited via TreeNodeBase
	virtual int GetColumnCount() const override;
	virtual CString GetColumnInfo(int column, int& width, int& format) const override;
	virtual int GetRowCount() override;
	virtual CString GetColumnText(int row, int col) const override;
	virtual int GetRowIcon(int row) const override;
	virtual bool InitList() override;
	virtual void TermList() override;
	virtual void SortList(int col, bool asc) override;

private:
	DataTarget* _dt;
	CLRDATA_ADDRESS _ad;
	std::vector<AssemblyInfo> _assemblies;
};


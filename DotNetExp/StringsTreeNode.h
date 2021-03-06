#pragma once
#include "TreeNodeBase.h"
#include "DataTarget.h"
#include "SortedFilteredVector.h"

class StringsTreeNode : public TreeNodeBase, public IFilterBarCallback {
public:
	StringsTreeNode(CTreeItem item, DataTarget* dt);

	// Inherited via TreeNodeBase
	virtual int GetColumnCount() const override;
	virtual CString GetColumnInfo(int column, int& width, int& format) const override;
	virtual int GetRowCount() override;
	virtual CString GetColumnText(int row, int col) const override;
	virtual bool InitList() override;
	virtual void TermList() override;
	virtual void SortList(int col, bool asc) override;
	virtual int GetRowIcon(int row) const override;
	virtual IFilterBarCallback* GetFilterBarCallback(IFilterBar* fb) override;

	// Inherited via IFilterBarCallback
	virtual int ApplyFilter(const CString& text) override;

private:
	DataTarget* _dt;
	SortedFilteredVector<ObjectInfo> _items;
	IFilterBar* _fb;
};


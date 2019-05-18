#include <iostream>
#include <xlnt/xlnt.hpp>

int main()
{
    xlnt::workbook wb;
    wb.load("Cursos.xlsx");
    auto ws = wb.active_sheet();
    std::clog << "Processing spread sheet" << std::endl;
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
    {
        std::clog << cell.to_string() << std::endl;
    }
    }
    std::clog << "Processing complete" << std::endl;
    return 0;
}

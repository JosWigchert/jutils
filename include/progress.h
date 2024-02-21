#include <cstdint>
#include <string>

class Progress {
public:
    Progress(const std::string& name);
    ~Progress();

public:
    void set_total(uint32_t total);
    void update(uint32_t current);
    void print();

private:
    uint8_t num_digits(uint32_t value);
    void get_progress_string(std::string& progress);

private:
    std::string _name;
    uint32_t _total;
    uint32_t _current;

    uint8_t bar_length = 20;
    uint8_t _current_bar_index = -1;
};

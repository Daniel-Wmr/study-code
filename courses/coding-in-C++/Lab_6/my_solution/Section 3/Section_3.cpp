#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Device
{
public:
    enum class DeviceType
    {
        Speaker,
        Microphone,
        Display,
        Network_Storage
    };

    std::string type_to_string(const DeviceType& type) const;

protected:
    std::string name;
    DeviceType type;
    bool power_status = false;

public:
    Device(const std::string& name, DeviceType type)
        : name(name), type(type){}

    void turn_on()
    {
        power_status = true;
    }

    void turn_off()
    {
        power_status = false;
    }

    std::string get_name() const
    {
        return name;
    }

    void print_info() const;

    virtual ~Device()
    {
        std::cout << "Device destroyed: " << name << std::endl;
    }
};

void Device::print_info() const
{
    std::cout << "Devices name: " << name << std::endl;
    std::cout << "Type: " << type_to_string(type) << std::endl;
    std::cout << "Power: " << (power_status ? "On" : "Off") << std::endl;
}

std::string Device::type_to_string(const DeviceType& type) const
{
    switch (type)
    {
    case DeviceType::Speaker: 
        return "Speaker";
    case DeviceType::Microphone:
        return "Microphone";
    case DeviceType::Display:
        return "Display";
    case DeviceType::Network_Storage:
        return "Network Storage";
    default:
        return "Unknown";
    }
}

class SharedDevice : public Device
{
private:
    const std::string ip_address;
    bool connection_status = false;

public:
    SharedDevice(const std::string& name, DeviceType type, const std::string& ip_address, bool status)
    : Device(name, type),
      ip_address(ip_address),
      connection_status(status){}
    void connect_to_network()
    {
        connection_status = true;
    }

    void disconnect_from_network()
    {
        connection_status = false;
    }

    void print_network_info() const
    {
        print_info();
        std::cout << "IP adress: " << ip_address << std::endl;
        std::cout << "Connection status: " << (connection_status ? "Connected" : "Disconnected") << std::endl;
    }

    ~SharedDevice()
    {
        std::cout << "SharedDevice destroyed...\n";
    }
};

class Room
{
private:
    std::string name;
    std::vector<std::unique_ptr<Device>> unique_devices;
    std::vector<std::shared_ptr<SharedDevice>> shared_devices;

public:
    Room(const std::string& name)
        : name(name){}

    void add_unique_device(std::unique_ptr<Device> device);
    void add_shared_device(const std::shared_ptr<SharedDevice>& device);
    void remove_device_by_name(const std::string& name);
    void print_unique_devices() const;
    void print_shared_devices() const;
};

void Room::add_unique_device(std::unique_ptr<Device> device)
{
    unique_devices.push_back(std::move(device));
}

void Room::add_shared_device(const std::shared_ptr<SharedDevice>& device)
{
    shared_devices.push_back(device);
}

void Room::remove_device_by_name(const std::string& name)
{
    auto it1 = std::find_if(
        unique_devices.begin(), 
        unique_devices.end(), 
        [&name](const std::unique_ptr<Device>& device)
        {
            return device->get_name() == name;
        });

    if (it1 != unique_devices.end())
    {
        unique_devices.erase(it1);
        return;
    }
        
    auto it2 = std::find_if(
            shared_devices.begin(), 
            shared_devices.end(), 
            [&name](const std::shared_ptr<SharedDevice>& device)
            {
                return device->get_name() == name;
            });

        if (it2 != shared_devices.end())
        {
            shared_devices.erase(it2);
            return;
        }

    std::cout << "Device not found.\n";
}

void Room::print_unique_devices() const
{
    std::cout << "=== Unique Devices ===" << std::endl;
    for (const auto& device : unique_devices)
    {
        device->print_info();
    }
}

void Room::print_shared_devices() const
{
    std::cout << "=== Shared Devices ===" << std::endl;
    for (const auto& device : shared_devices)
    {
        device->print_network_info();
    }
}

int main()
{
    auto nas = std::make_shared<SharedDevice>(
        "Central NAS",
        Device::DeviceType::Network_Storage,
        "192.168.0.10",
        false);

    std::cout << "\n=== Shared Pointer Counter Test ===\n";

    std::cout << "After creation: "
              << nas.use_count()
              << std::endl;

    {
        Room living_room("Living Room");
        Room studio("Recording Studio");

        auto speaker = std::make_unique<Device>(
            "JBL Speaker",
            Device::DeviceType::Speaker);

        auto microphone = std::make_unique<Device>(
            "Rode Microphone",
            Device::DeviceType::Microphone);

        auto display = std::make_unique<Device>(
            "Samsung Display",
            Device::DeviceType::Display);

        living_room.add_unique_device(std::move(speaker));
        studio.add_unique_device(std::move(microphone));
        living_room.add_unique_device(std::move(display));

        living_room.add_shared_device(nas);

        std::cout << "After adding to living room: "
                  << nas.use_count()
                  << std::endl;

        studio.add_shared_device(nas);

        std::cout << "After adding to studio: "
                  << nas.use_count()
                  << std::endl;

        nas->connect_to_network();

        std::cout << "\n=== Living Room ===\n";
        living_room.print_unique_devices();
        living_room.print_shared_devices();

        std::cout << "\n=== Studio ===\n";
        studio.print_unique_devices();
        studio.print_shared_devices();

        std::cout << "\nRemoving JBL Speaker...\n";
        living_room.remove_device_by_name("JBL Speaker");

        std::cout << "\nCount before rooms are destroyed: "
                  << nas.use_count()
                  << std::endl;
    }

    std::cout << "\nAfter rooms are destroyed: "
              << nas.use_count()
              << std::endl;

    return 0;
}
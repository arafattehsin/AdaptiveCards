#pragma once
#include <string>
#include <vector>

namespace AdaptiveCards
{
    enum class TextSectionFormat : uint16_t
    {
        RegularString = 0,
        Time,
        DateCompact,
        DateShort,
        DateLong
    };

    class TextSection
    {
    public:
        TextSection(); 
        TextSection(std::string text, TextSectionFormat format);

        std::string GetText() const;
        std::string GetOriginalText() const;
        TextSectionFormat GetFormat() const;
        int GetDay() const;
        int GetMonth() const;
        int GetYear() const;
        int GetSecond() const;
        int GetMinute() const;
        int GetHour() const;

    private:
        std::vector<std::string> Split(const std::string& in, char delimiter) const;

        std::string m_text;
        std::string m_originalText;
        TextSectionFormat m_format;
    };
    
    class TextBlockText
    {
    public:
        TextBlockText();
        TextBlockText(std::string in);
        std::vector<TextSection> GetString() const;
        void AddTextSection(std::string text, TextSectionFormat format);
        std::string Concatenate();

    private:
        std::u16string ToU16String(const std::string& in) const;
        std::u16string ToU16String(const std::wstring& in) const;

        std::wstring StringToWstring(const std::string& in) const;
        std::string WstringToString(const std::wstring& in) const;

        static bool IsValidTimeAndDate(const struct tm &parsedTm, int hours, int minutes);
        void ParseDateTime(std::string in);        

        std::vector<TextSection> m_fullString;
    };
}
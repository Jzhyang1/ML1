class media
{
private:
    enum {
        image,
        audio,
        video,
        text,
        file
    } media_type;

    union {
        void* data;
        char* text;
    } media_data;
    
public:
    media(/* args */);
};

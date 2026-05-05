import kagglehub

# Download latest version
path = kagglehub.dataset_download("developerghost/climate-in-india-daily-weather-data-2000-2024")

print("Path to dataset files:", path)
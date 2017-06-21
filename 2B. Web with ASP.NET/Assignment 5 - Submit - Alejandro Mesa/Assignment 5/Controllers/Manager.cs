using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_5.Models;

namespace Assignment_5.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        // AutoMapper instance
        public IMapper mapper;

        public Manager()
        {
            // If necessary, add more constructor code here...

            // Configure the AutoMapper components
            var config = new MapperConfiguration(cfg =>
            {
                // Define the mappings below, for example...
                // cfg.CreateMap<SourceType, DestinationType>();
                // cfg.CreateMap<Employee, EmployeeBase>();


                cfg.CreateMap<Models.Album, Controllers.AlbumBase>();
                cfg.CreateMap<Models.Artist, Controllers.ArtistBase>();
                cfg.CreateMap<Models.MediaType, Controllers.MediaTypeBase>();

                cfg.CreateMap<Models.Track, Controllers.TrackBase>();
                cfg.CreateMap<Models.Track, Controllers.TrackWithDetail>();

                cfg.CreateMap<Controllers.TrackAdd, Models.Track>();


            });

            mapper = config.CreateMapper();

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        public IEnumerable<TrackBase> TrackGetAll()
        {
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackBase>>(ds.Tracks.OrderBy(o => o.TrackId));
        }

        public IEnumerable<TrackBase> TrackGetAllWithDetails()
        {
            var sort = ds.Tracks
              .Include("Album.Artist")
              .Include("MediaType")
              .OrderBy(t => t.TrackId);
            return mapper.Map<IEnumerable<Track>, IEnumerable<TrackWithDetail>>(sort);
        }

        public TrackBase TrackGetById(int id)
        {
            var o = ds.Tracks.Find(id);

            return (o == null) ? null : mapper.Map<Track, TrackBase>(o);
        }

        public TrackWithDetail TrackGetByIdWithDetail(int id)
        {
            var o = ds.Tracks.Find(id);
            ds.Tracks.Include("Album.Artist")
              .Include("MediaType")
              .SingleOrDefault(t => t.TrackId == id);
            return (o == null) ? null : mapper.Map<Track, TrackWithDetail>(o);
        }

        public TrackWithDetail TrackAdd(TrackAdd addTrack)
        {
            var addAlbum = ds.Albums.Find(addTrack.AlbumId);
            var addMediaType = ds.MediaTypes.Find(addTrack.MediaTypeId);

            var addItem = ds.Tracks.Add(mapper.Map<TrackAdd, Track>(addTrack));

            addItem.Album = addAlbum;
            addItem.MediaType = addMediaType;
            ds.SaveChanges();

            return (addItem == null) ? null : mapper.Map<Track, TrackWithDetail>(addItem);
        }


        //Others
        //Album
        public IEnumerable<AlbumBase> AlbumGetAll()
        {
            return mapper.Map<IEnumerable<Album>, IEnumerable<AlbumBase>>(ds.Albums);
        }

        public AlbumBase AlbumGetById(int id)
        {
            var o = ds.Albums.Find(id);

            return (o == null) ? null : mapper.Map<Album, AlbumBase>(o);
        }

        //Artist
        public IEnumerable<ArtistBase> ArtistGetAll()
        {
            return mapper.Map<IEnumerable<Artist>, IEnumerable<ArtistBase>>(ds.Artists);
        }

        public ArtistBase ArtistGetById(int id)
        {
            var o = ds.Artists.Find(id);

            return (o == null) ? null : mapper.Map<Artist, ArtistBase>(o);
        }

        //MediaType
        public IEnumerable<MediaTypeBase> MediaTypeGetAll()
        {
            return mapper.Map<IEnumerable<MediaType>, IEnumerable<MediaTypeBase>>(ds.MediaTypes);
        }

        public MediaTypeBase MediaTypeGetById(int id)
        {
            var o = ds.MediaTypes.Find(id);

            return (o == null) ? null : mapper.Map<MediaType, MediaTypeBase>(o);
        }


    }
}
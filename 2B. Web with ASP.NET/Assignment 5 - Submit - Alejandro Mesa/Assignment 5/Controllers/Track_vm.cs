using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Web.Mvc;

namespace Assignment_5.Controllers
{
    public class TrackAdd
    {
        [Key]
        public int TrackId { get; set; }
        [Display(Name = "Track name")]
        public string Name { get; set; }

        public int? AlbumId { get; set; }

        public int MediaTypeId { get; set; }

        public int? GenreId { get; set; }

        public string Composer { get; set; }

        [Display(Name = "Length (ms)")]
        public int Milliseconds { get; set; }

        public int? Bytes { get; set; }

        [Display(Name = "Unit price")]
        public decimal UnitPrice { get; set; }

        [Display(Name = "Artist name")]
        public string AlbumArtistName { get; set; }

        [Display(Name = "Album title")]
        public string AlbumTitle { get; set; }

        [Display(Name = "Media Type Name")]
        public string MediaTypeName { get; set; }


    }
    public class TrackWithDetail : TrackBase
    {
        [Display(Name = "Artist name")]
        public new string AlbumArtistName { get; set; }

        [Display(Name = "Album title")]
        public new string AlbumTitle { get; set; }

        public MediaTypeBase MediaType { get; set; }
    }

    public class TrackBase : TrackAdd
    {
        [Key]
        public new int TrackId { get; set; }
    }

    public class TrackAddForm : TrackAdd
    {
        [Display(Name = "Album")]
        public SelectList AlbumList { get; set; }

        public new string AlbumTitle { get; set; }

        [Display(Name = "Media Type")]
        public SelectList MediaTypeList { get; set; }
    }
}